/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isthink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:35:38 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 16:39:02 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isthink(t_fork *fork, int index, int time_to_die, t_table *table)
{
	long int	time;
	int			ttd;

	time = ft_gettime();
	ttd = time_to_die;
	pthread_mutex_lock(&(table->print));
	printf("%ld %d is thinking\n", time, index);
	pthread_mutex_unlock(&(table->print));
	while (*(fork->fork_state) == 1 && time_to_die > 0 && table->dead == 0)
	{
		usleep(1000);
		time_to_die--;
	}
	if (table->dead == 1)
		return (-1);
	if (time_to_die == 0)
	{
		pthread_mutex_lock(&(table->print));
		printf("%ld %d has died\n", time + ttd, index);
		table->dead = 1;
	}
	return (time_to_die);
}
