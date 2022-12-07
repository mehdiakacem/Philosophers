/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:51:50 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 16:39:28 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_destroy_mutex(t_table *table, int nbr_of_philos)
{
	int	i;

	i = 1;
	pthread_mutex_destroy(&(table->print));
	while (i <= nbr_of_philos)
	{
		pthread_mutex_destroy(&(table->philos->fork));
		table->philos = table->philos->next;
		i++;
	}
}
