/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:30 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/06 17:32:32 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define UC unsigned char
# define UI unsigned int
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#define BUFF_SIZE 100
#define NX navi->next
#define NCF ((t_lol *)(navi)->content)->fdi
#define BB buffer->buff

#include <fcntl.h>
#include "libft.h"
#include <stdio.h>


typedef struct	s_gnl
{
	int fdi;
	char buff[BUFF_SIZE + 1];
	char *tmp;
}				t_gnl;


typedef struct 	s_lol
{
	int fdi;
	char buff[BUFF_SIZE + 1];
} 				t_lol;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_strclen(const char *s, char c);
char			*ft_strdup(char *src, int freesrc);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *src, int c);
char			*ft_strrchr(const char *src, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalldigit(char *src);
int				ft_isalnum(int c);
int				ft_isnum_no_zero(char c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size, char c);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size, char c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
int				ft_finder(const char *str, char c);
int				ft_lenbeforec(const char *src, char c);
char			**ft_splitter(char **dest, char const *src, char c);
char			**ft_strsplit(char const *s, char c);
void			ft_putnbr(int n);
void			ft_putchar(unsigned char c);
int				ft_putstr(char const *str);
int				ft_putunicode(int c);
int				ft_putunicodesup(int c);
int				ft_putstr_until_a(char *str, char a);
int				ft_putstr_a_to_b(char *str, char a, char b);
int				ft_strintlen(intmax_t nbr);
char			*ft_itoa(intmax_t n);
char			*ft_utoa(uintmax_t n);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*ft_del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*ft_del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_del(void *alst, size_t size);
int				ft_ifmanyinchain(char const *s);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa_base(uintmax_t nbr, char *base);
int				ft_base_check(char *str);
char			*ft_append(char *s1, char *s2, int b);
int				ft_no_encounter(char *str, char *caras);
char			ft_encounter(char *str, char *caras);
int				ft_no_encounter_until(char *str, char *caras, char c);
int				ft_no_encounter_until_index(char *str, char *caras, char c);
void			ft_str_fill_nchar_lr(char *str, char c, int n);
void			ft_str_fill_nchar_rl(char *str, char c, int n);
char			*ft_place_in_str(char *dst, char *src, int a, int b);
char			*ft_morealloc(char *src, int n, int where);
int				ft_isallhexa(char *src);
int				ft_isallsame(char *str, char a);
int				ft_size_unicode(int c);
int				ft_count_char(char *src, char c);
int				ft_no_encounter_index(char *str, char *caras);
int 			get_next_line(const int fd, char **line);

#endif
