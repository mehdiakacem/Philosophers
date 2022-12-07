/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:38:24 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 16:41:14 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_sleep(int time_to_sleep, int index, t_table *table, int time_to_die)
{
	int			ttd;
	long int	time;

	ttd = time_to_die;
	time = ft_gettime();
	pthread_mutex_lock(&(table->print));
	printf("%ld %d is sleeping\n", time, index);
	pthread_mutex_unlock(&(table->print));
	if (time_to_die - time_to_sleep < 0)
	{
		usleep((time_to_sleep - ttd) * 1000);
		pthread_mutex_lock(&(table->print));
		printf("%ld %d has died\n", time + time_to_die, index);
		table->dead = 1;
		return (0);
	}
	usleep(time_to_sleep * 1000);
	return (ttd - time_to_sleep);
}
