# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/18 15:52:10 by susivagn          #+#    #+#              #
#    Updated: 2018/02/01 05:47:28 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = parsefiller.c \
	  filler_read.c \
	  play_filler.c \
	  chauffage_filler.c \
	  

OFILE = $(SRC:.c=.o)

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILE)
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)


%.o: %.c
	gcc $(FLAGS) -c -g $^

clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all