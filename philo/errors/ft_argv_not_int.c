/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_not_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:42:49 by makacem           #+#    #+#             */
/*   Updated: 2022/11/30 15:55:24 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

int	ft_check_isdigit(char *argv)
{
	while (*argv != '\0')
	{
		if (*argv == '-' && ft_isdigit(*(argv + 1)) == 0)
			return (1);
		if (ft_isdigit(*argv) == 0)
			return (1);
		argv++;
	}
	return (0);
}

int	ft_argv_not_int(int argc, char **argv)
{
	int	nbr_of_args;
	int	i;

	nbr_of_args = argc - 1;
	i = 1;
	while (i <= nbr_of_args)
	{
		if (ft_check_isdigit(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
