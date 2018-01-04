# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 17:53:05 by susivagn          #+#    #+#              #
#    Updated: 2018/01/04 14:49:50 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_bzero.c \
	  ft_memset.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strcat.c \
	  ft_strncpy.c \
	  ft_strncat.c \
	  ft_strlen.c \
	  ft_strclen.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_finder.c \
	  ft_lenbeforec.c \
	  ft_strsplit.c \
	  ft_splitter.c \
	  ft_putnbr.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_itoa.c \
	  ft_utoa.c \
	  ft_strintlen.c \
	  ft_putendl.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_del.c \
	  ft_ifmanyinchain.c \
	  ft_atoi_base.c \
	  ft_itoa_base.c \
	  ft_base_check.c \
	  ft_append.c \
	  ft_no_encounter_char.c \
	  ft_encounter.c \
	  ft_no_encounter_until.c \
	  ft_no_encounter_until_index.c \
	  ft_no_encounter_index.c \
	  ft_isnum_no_zero.c \
	  ft_putstr_a_to_b.c \
	  ft_putunicode.c \
	  ft_putstr_until_a.c \
	  ft_str_fill_nchar.c \
	  ft_place_in_str.c \
	  ft_morealloc.c \
	  ft_isalldigit.c \
	  ft_isallhexa.c \
	  ft_printf.c \
	  ft_start_parsing.c \
	  ft_start.c \
	  ft_size_unicode.c \
	  ft_count_char.c \
	  ft_isallsame.c \
	  ft_process_char_str.c \
	  ft_process_sign.c \
	  ft_process_htag.c \
	  ft_process_precision_flag.c \
	  ft_lenmod_unsign.c \
	  ft_lenmod_signed.c \
	  ft_start.c \
	  ft_start_processing.c \
	  get_next_line.c \
	  ft_addchartable.c \
	  ft_addinttable.c \
	  ft_print_table.c

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