/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:17:19 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 15:27:26 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_fork(t_fork *fork, int index, t_table *table)
{
	pthread_mutex_lock(fork->fork);
	*(fork->fork_state) = 1;
	pthread_mutex_lock(&(table->print));
	printf("%ld %d has taken a fork\n", ft_gettime(), index);
	pthread_mutex_unlock(&(table->print));
}
