# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:29:08 by makacem           #+#    #+#              #
#    Updated: 2022/12/05 12:45:42 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = -Wall -Werror -Wextra

HEADER = philo.h

SRC = main.c \
	errors/ft_argv_not_int.c \
	errors/ft_check_errors.c \
	errors/ft_checkargs.c \
	errors/ft_display_error.c \
	args/ft_init_args.c \
	args/ft_atoi.c \
	philos/ft_create_philos.c \
	philos/ft_start_philos.c \
	philos/ft_start_nphilos.c \
	philos/ft_free_philos.c \
	philos/ft_destroy_mutex.c \
	philos/ft_check_death.c \
	routine/ft_gettime.c \
	routine/ft_think.c \
	routine/ft_isthink.c \
	routine/ft_fork.c \
	routine/ft_eat.c \
	routine/ft_unfork.c \
	routine/ft_sleep.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	
%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -pthread -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all