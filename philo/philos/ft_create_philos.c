/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 08:43:30 by makacem           #+#    #+#             */
/*   Updated: 2022/11/21 18:41:05 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_create_philos(t_table *table)
{
	t_node	*new_philo;
	int		i;

	i = 1;
	table->philos = NULL;
	while (i <= table->arguments.number_of_philos)
	{
		new_philo = (t_node *)malloc(sizeof(t_node));
		if (table->philos == NULL)
		{
			new_philo->index = i;
			new_philo->next = new_philo;
			table->philos = new_philo;
		}
		else
		{
			new_philo->index = i;
			new_philo->next = table->philos->next;
			table->philos->next = new_philo;
			table->philos = new_philo;
		}
		i++;
	}
}
