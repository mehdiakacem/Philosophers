/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:26:26 by makacem           #+#    #+#             */
/*   Updated: 2022/12/02 12:03:46 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free_philos(t_table *table)
{
	t_node	*node;
	t_node	*temp;
	int		i;

	i = 1;
	node = table->philos;
	while (i <= table->arguments.number_of_philos)
	{
		temp = node;
		free(node);
		node = temp->next;
		i++;
	}
}
