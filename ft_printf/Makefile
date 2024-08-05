# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 11:45:56 by malsheri          #+#    #+#              #
#    Updated: 2024/04/27 23:36:29 by malsheri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c handle_char.c handle_string.c handle_unum.c \
		handle_hexa.c handle_num.c handle_pointer.c

OBJECTS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJECTS)
			ar -rcs $(NAME) $(OBJECTS)

all: $(NAME)

# %.o: %.c 
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re