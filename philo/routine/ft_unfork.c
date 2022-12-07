/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:43:34 by makacem           #+#    #+#             */
/*   Updated: 2022/11/30 09:16:48 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_unfork(t_fork *fork, t_fork *n_fork)
{
	pthread_mutex_unlock(fork->fork);
	pthread_mutex_unlock(n_fork->fork);
	*(fork->fork_state) = 0;
	*(n_fork->fork_state) = 0;
}
