/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:32:01 by makacem           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:55 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct args
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_tms_pilos_eat;
}	t_args;

typedef struct node
{
	pthread_t		philosopher;
	pthread_mutex_t	fork;
	int				fork_state;
	int				index;
	struct node		*next;
}	t_node;

typedef struct table
{
	pthread_mutex_t	print;
	t_args			arguments;
	t_node			*philos;
	int				dead;
	int				count;
}	t_table;

typedef struct fork
{
	int				n_eat;
	pthread_mutex_t	*fork;
	int				*fork_state;
	int				ttd;
}	t_fork;

int			ft_check_errors(int argc, char **argv);
int			ft_argv_not_int(int argc, char **argv);
int			ft_checkargs(int argc);
void		ft_display_error(void);
void		ft_init_args(int argc, char **argv, t_table *table);
int			ft_atoi(const char *str);
void		ft_create_philos(t_table *table);
void		ft_start_philos(t_table *table);
void		ft_start_nphilos(t_table *table);
void		ft_free_philos(t_table *table);
long int	ft_gettime(void);
int			ft_think(t_fork *fork, t_fork *n_fork, int index, t_table *table);
int			ft_isthink(t_fork *fork, int index, int time_to_die,
				t_table *table);
void		ft_fork(t_fork *fork, int index, t_table *table);
int			ft_eat(int time_to_eat, int index, t_table *table);
void		ft_unfork(t_fork *fork, t_fork *n_fork);
int			ft_usleep(long int i);
int			ft_sleep(int time_to_sleep, int index, t_table *table,
				int time_to_die);
void		ft_destroy_mutex(t_table *table, int nbr_of_philos);
void		ft_check_death(t_table *table);

#endif