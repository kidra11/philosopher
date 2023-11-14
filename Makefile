# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:35:05 by nsion             #+#    #+#              #
#    Updated: 2023/11/08 14:13:39 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c thread.c utils.c \
	ft_printf/ft_printf.c ft_printf/ft_find.c \

NAME = philo

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -pthread

RM = rm -f

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.OBJS:
	$(GCC) $(CFLAGS) $(LFLAGS) -I ./ -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(GCC) $(CFLAGS) $(LFLAGS) $(OBJS) -I ./ -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re