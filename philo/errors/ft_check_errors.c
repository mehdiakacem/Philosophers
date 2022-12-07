/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:35:10 by makacem           #+#    #+#             */
/*   Updated: 2022/11/30 15:59:30 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_errors(int argc, char **argv)
{
	if (ft_checkargs(argc) == 1)
		return (1);
	else if (ft_argv_not_int(argc, argv) == 1)
	{
		ft_display_error();
		return (1);
	}
	return (0);
}
