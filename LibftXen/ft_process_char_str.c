/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:32:39 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 15:04:52 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_char(char c, t_printf *m_struct)
{
	int		i;
	char	*cpystr;

	i = 0;
	if (c == 'c' && m_struct->modl == 0)
		ft_char(m_struct);
	if ((m_struct->modl == 1 && c == 'c') || c == 'C')
		ft_big_char(m_struct);
	if (c == 's' && m_struct->modl == 0)
	{
		if (!(cpystr = ft_strdup((char*)va_arg(m_struct->vap, char*), 0)))
			m_struct->buffer = ft_strdup(cpystr, 1);
		if (m_struct->flagprecision != -1)
			ft_process_precision_str(cpystr, c, m_struct);
		else
			m_struct->buffer = ft_strdup(cpystr, 1);
		ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
	}
	if (c == '%')
	{
		m_struct->buffer = ft_strdup("%", 0);
		ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
	}
	if ((c == 'S') || (c == 's' && m_struct->modl == 1))
		ft_big_s(m_struct);
}

void	ft_big_s(t_printf *m_struct)
{
	va_arg(m_struct->vap, void*);
	return ;
}

char	*ft_getwchar(int c)
{
	char	*wchar;

	wchar = ft_strnew(5, '\0');
	if (c < 0x80)
		wchar[0] = c;
	else if ((c >= 0x80) && (c < 0x800))
	{
		wchar[0] = ((c >> 6) | 0xC0);
		wchar[1] = ((c & 0x3F) | 0x80);
	}
	else if ((c >= 0x800) && (c < 0x10000))
	{
		wchar[0] = ((c >> 12) | 0xE0);
		wchar[1] = (((c >> 6) & 0x3F) | 0X80);
		wchar[2] = ((c & 0x3F) | 0x80);
	}
	else if ((c >= 0x10000) && (c <= 0x10FFFF))
	{
		wchar[0] = ((c >> 18) | 0xF0);
		wchar[1] = (((c >> 12) & 0x3F) | 0X80);
		wchar[2] = (((c >> 6) & 0x3F) | 0X80);
		wchar[3] = ((c & 0x3F) | 0x80);
	}
	return (wchar);
}

void	ft_char(t_printf *m_struct)
{
	char	c;

	c = (char)va_arg(m_struct->vap, void*);
	if (c == 0)
		m_struct->len++;
	if (!c && m_struct->flagminus == 1)
		write(1, "\0", 1);
	if (!c && m_struct->flagzero != -1)
		m_struct->lm--;
	if (c == 0 && m_struct->flagwidth > 0)
		m_struct->lm--;
	m_struct->buffer = ft_strnew(2, '\0');
	m_struct->buffer[0] = c;
	ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
	if (!c && m_struct->flagminus == 0)
	{
		m_struct->len += ft_putstr(m_struct->buffer);
		write(1, "\0", 1);
		*m_struct->buffer = 0;
	}
}

int		ft_big_char(t_printf *m_struct)
{
	int		c;
	int		taille;

	c = (int)va_arg(m_struct->vap, void*);
	if (c == 0)
		m_struct->len++ && write(1, "\0", 1);
	taille = ft_size_unicode(c);
	m_struct->buffer = ft_getwchar(c);
	return (taille);
}
