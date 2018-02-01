# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/18 15:52:10 by susivagn          #+#    #+#              #
#    Updated: 2018/02/01 07:09:23 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = susivagn.filler

SRC = parse_filler.c \
	  filler_read.c \
	  play_filler.c \
	  chauffage_filler.c

LIB = LibftXen/libftprintf.a

OFILE = $(SRC:.c=.o)

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OFILE)
	make -C LibftXen
	gcc $(SRC) $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	make clean -C LibftXen
	rm -f $(OFILE)

fclean: clean
	make fclean -C LibftXen
	rm -f $(NAME)

re: fclean all