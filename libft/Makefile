# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obibik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 21:43:20 by obibik            #+#    #+#              #
#    Updated: 2018/12/28 21:43:22 by obibik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2

SOURCES = ./src/ft_*.c ./ft_printf/*.c

INCLUDE = header

OBJS = ./src/ft_*.o ./ft_printf/*.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SOURCES) -I $(INCLUDE)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
