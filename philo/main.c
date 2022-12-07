/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:27:29 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 16:58:03 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (ft_check_errors(argc, argv) == 1)
		return (0);
	ft_init_args(argc, argv, &table);
	ft_create_philos(&table);
	if (argc == 5)
		ft_start_philos(&table);
	else if (table.arguments.nbr_tms_pilos_eat > 0)
		ft_start_nphilos(&table);
	ft_free_philos(&table);
	return (0);
}
