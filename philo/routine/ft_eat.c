/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:29:44 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 16:01:15 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_eat(int time_to_eat, int index, t_table *table)
{
	int			ttd;
	long int	time;

	ttd = table->arguments.time_to_die;
	time = ft_gettime();
	pthread_mutex_lock(&(table->print));
	printf("%ld %d is eating\n", time, index);
	pthread_mutex_unlock(&(table->print));
	if (table->arguments.time_to_die - time_to_eat < 0)
	{
		usleep((time_to_eat - ttd) * 1000);
		pthread_mutex_lock(&(table->print));
		printf("%ld %d has died\n", time + table->arguments.time_to_die, index);
		table->dead = 1;
		return (0);
	}
	usleep(time_to_eat * 1000);
	return (ttd - time_to_eat);
}
