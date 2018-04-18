# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 10:41:06 by agrodzin          #+#    #+#              #
#    Updated: 2018/04/18 14:53:39 by zbruce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Werror -Wextra
SRCS=libft/ft_putchar.c libft/ft_putstr.c libft/ft_strlen.c libft/ft_putnbr.c libft/ft_putendl.c libft/ft_bzero.c ft_get_and_check.c ft_setup.c normalise.c check_put_board.c after_board_false.c fillit_try.c
NAME=fillit

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) -c ft_get_and_check.c
	$(CC) -c ft_setup.c
	$(CC) -c normalise.c
	$(CC) -c check_put_board.c
	$(CC) -c after_board_false.c
	$(CC) -c fillit_try.c
	$(CC) -c libft/ft_putchar.c
	$(CC) -c libft/ft_putstr.c
	$(CC) -c libft/ft_strlen.c
	$(CC) -c libft/ft_putnbr.c
	$(CC) -c libft/ft_bzero.c
	$(CC) -c libft/ft_putendl.c
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	/bin/rm -f ft_get_and_check.o ft_setup.o normalise.o check_put_board.o after_board_false.o fillit_try.o ft_putchar.o ft_putstr.o ft_strlen.o ft_putnbr.o ft_bzero.o ft_putendl.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf libft/libft.a

re: fclean all
