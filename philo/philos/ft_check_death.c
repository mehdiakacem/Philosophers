/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:44:41 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 16:40:37 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*dloop(void *args)
{
	t_table	*temp;
	int		i;

	temp = (t_table *)args;
	temp->count = 0;
	while (temp->dead == 0 && temp->count < temp->arguments.number_of_philos)
	{
	}
	if (temp->dead == 1)
	{
		i = 0;
		while (++i <= temp->arguments.number_of_philos)
		{
			pthread_detach(temp->philos->philosopher);
			temp->philos = temp->philos->next;
		}
	}
	return (NULL);
}

void	ft_check_death(t_table *table)
{
	pthread_t		death;

	pthread_create(&death, NULL, &dloop, table);
	pthread_join(death, NULL);
}
