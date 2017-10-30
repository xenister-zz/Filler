/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:22:17 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/29 11:49:15 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft.h"

/*
**  SET ALL DEFAULT
*/

# define C_DEFAULT	"\033[m"

/*
**  TEXT COLOR
*/

# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENDA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

/*
**  ANSI TEXT COLOR
*/

# define X_BLACK	"\033[1;30m"
# define X_RED		"\033[1;31m"
# define X_GREEN	"\033[1;32m"
# define X_YELLOW	"\033[1;33m"
# define X_BLUE		"\033[1;34m"
# define X_MAGENDA	"\033[1;35m"
# define X_CYAN		"\033[1;36m"
# define X_WHITE	"\033[1;37m"

/*
**  FONT COLOR
*/

# define F_BLACK	"\033[40m"
# define F_RED		"\033[41m"
# define F_GREEN	"\033[42m"
# define F_YELLOW	"\033[43m"
# define F_BLUE		"\033[44m"
# define F_MAGENDA	"\033[45m"
# define F_CYAN		"\033[46m"
# define F_WHITE	"\033[47m"

/*
**  TEXT EDIT
*/

# define T_BOLD			"\033[1m"
# define T_ITALIC		"\033[3m"
# define T_UNDERLINED	"\033[4m"
# define T_INVERTED		"\033[7m"

typedef struct	s_printf
{
	va_list	vap;
	int		flag;
	int		flagminus;
	int		flagplus;
	int		flaghtag;
	int		flagspace;
	int		flagprecision;
	int		flagzero;
	int		flagwidth;
	int		lm;
	int		nomod;
	int		modhh;
	int		modh;
	int		modll;
	int		modl;
	int		modj;
	int		modz;
	char	*buffer;
	int		len;
}				t_printf;

int				ft_printf(char *arg, ...);
void			ft_noflags(char *arg, t_printf *m_struct);
char			*conv_hexa(uintmax_t nbr, char c);
void			init_struct_flag_lenmod(t_printf *m_struct);
int				ft_pourcent_chck(char *arg, int i, int l, t_printf *m_struct);
int				ft_starter_with_flags(char *arg, t_printf *m_struct);
int				ft_get_width_precision_zero(char *arg, int b, t_printf
	*m_struct);
void			ft_get_len_mod(char *arg, char c, t_printf *m_struct);
void			ft_get_flags(char *arg, char c, t_printf *m_struct);
void			ft_place_htag_pres(int sign, t_printf *m_struct);
void			ft_place_htag(int sign, t_printf *m_struct, int i);
void			ft_put_htag_space_after(int sign, t_printf *m_struct);
void			ft_process_flag_str(int lenstr, t_printf *m_struct);
void			ft_process_precision_str(char *str, char c, t_printf *m_struct);
void			ft_process_precision_nbr(char *str, t_printf *m_struct);
void			ft_place_sign_pres(int sign, t_printf *m_struct);
void			ft_sign_zero(int sign, t_printf *m_struct);
void			ft_place_sign(int sign, t_printf *m_struct, int i);
void			ft_string_char(char c, t_printf *m_struct);
char			*ft_getwchar(int c);
void			ft_char(t_printf *m_struct);
int				ft_big_char(t_printf *m_struct);
intmax_t		ft_process_lenmod_signed(t_printf *m_struct);
intmax_t		ft_process_lenmod_signed_big(t_printf *m_struct);
void			ft_signed_numbers(char c, t_printf *m_struct);
uintmax_t		ft_process_lenmod_unsigned(char c, t_printf *m_struct);
uintmax_t		ft_process_lenmod_unsigned_big(t_printf *m_struct);
void			ft_unsigned_numbers(char c, t_printf *m_struct);
int				ft_start_processing(char c, t_printf *m_struct);
void			ft_print_adress(t_printf *m_struct);
int				ft_check_space(char *str);
void			ft_process_octal(t_printf *m_struct, int len);
int				ft_merde_checker(char *arg, int *i, int l, t_printf *m_struct);
int				ft_minicheck(char *arg, int i, t_printf *m_struct);
void			ft_set_init_flag(t_printf *m_struct);
int				ft_ending_no_pourcent(char *arg, int i, t_printf *m_struct);
void			ft_flag_space(t_printf *m_struct);
void			ft_big_s(t_printf *m_struct);
void			ft_process_hexa(t_printf *m_struct, int n, char c);

#endif
