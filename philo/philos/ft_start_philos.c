/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:42:26 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 15:23:33 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_table	*temp;
	int		index;
	t_fork	fork;
	t_fork	next_fork;

	temp = (t_table *)arg;
	index = temp->philos->index;
	fork.fork = &(temp->philos->fork);
	fork.fork_state = &(temp->philos->fork_state);
	next_fork.fork = &(temp->philos->next->fork);
	next_fork.fork_state = &(temp->philos->next->fork_state);
	fork.ttd = temp->arguments.time_to_die;
	while (temp->dead == 0)
	{
		fork.ttd = fork.ttd;
		fork.ttd = ft_think(&fork, &next_fork, index, temp);
		if (fork.ttd == 0)
			return (NULL);
		ft_unfork(&fork, &next_fork);
		fork.ttd = ft_sleep(temp->arguments.time_to_sleep,
				index, temp, fork.ttd);
	}
	return (NULL);
}

void	ft_start_philos(t_table *table)
{
	int	i;

	table->dead = 0;
	i = table->arguments.number_of_philos;
	while (--i >= 0)
	{
		pthread_mutex_init(&(table->philos->fork), NULL);
		table->philos = table->philos->next;
	}
	pthread_mutex_init(&(table->print), NULL);
	i = 0;
	while (++i <= table->arguments.number_of_philos)
	{
		pthread_create(&(table->philos->philosopher), NULL, &routine, table);
		usleep(1000);
		table->philos = table->philos->next;
	}
	ft_check_death(table);
	i = 0;
	while (++i <= table->arguments.number_of_philos)
	{
		pthread_join(table->philos->philosopher, NULL);
		table->philos = table->philos->next;
	}
	ft_destroy_mutex(table, table->arguments.number_of_philos);
}
