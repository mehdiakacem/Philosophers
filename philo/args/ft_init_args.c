/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:37:33 by makacem           #+#    #+#             */
/*   Updated: 2022/11/30 14:13:40 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_args(int argc, char **argv, t_table *table)
{
	table->arguments.number_of_philos = ft_atoi(argv[1]);
	table->arguments.time_to_die = ft_atoi(argv[2]);
	table->arguments.time_to_eat = ft_atoi(argv[3]);
	table->arguments.time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		table->arguments.nbr_tms_pilos_eat = ft_atoi(argv[5]);
}
