/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:35:36 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 15:27:17 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_think(t_fork *fork, t_fork *n_fork, int index, t_table *table)
{
	int	time_to_die;

	time_to_die = ft_isthink(fork, index, fork->ttd, table);
	if (time_to_die == 0)
	{
		table->dead = 1;
		return (0);
	}
	else if (time_to_die == -1)
		return (0);
	ft_fork(fork, index, table);
	time_to_die = ft_isthink(n_fork, index, time_to_die, table);
	if (time_to_die == 0)
	{
		table->dead = 1;
		return (0);
	}
	else if (time_to_die == -1)
		return (0);
	ft_fork(n_fork, index, table);
	time_to_die = ft_eat(table->arguments.time_to_eat, index, table);
	return (time_to_die);
}
