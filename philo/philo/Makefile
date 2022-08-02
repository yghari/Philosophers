# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yghari <yghari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:38:30 by yghari            #+#    #+#              #
#    Updated: 2022/05/27 02:33:52 by yghari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = philo_utils/ft_atoi.c \
	philo_utils/ft_strtrim.c \
	philo_utils/ft_substr.c \
	philo_utils/funct_utils.c \
	philo.c \
	philo_init.c \
	philo_errors.c \
	philo_manage.c \
	time_manage.c \
	philo_routine.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -pthread $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re: fclean all