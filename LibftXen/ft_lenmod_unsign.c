/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmod_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:20:51 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 17:17:53 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_process_lenmod_unsigned(char c, t_printf *m_struct)
{
	uintmax_t	nbr;

	if (c == 'U' || c == 'O')
		return (ft_process_lenmod_unsigned_big(m_struct));
	if (m_struct->modhh == 1)
		nbr = (unsigned char)va_arg(m_struct->vap, void*);
	else if (m_struct->modh == 1)
		nbr = (unsigned short)va_arg(m_struct->vap, void*);
	else if (m_struct->modl == 1)
		nbr = (unsigned long)va_arg(m_struct->vap, void*);
	else if (m_struct->modll == 1)
		nbr = (long long)va_arg(m_struct->vap, void*);
	else if (m_struct->modj == 1)
		nbr = (uintmax_t)va_arg(m_struct->vap, void*);
	else if (m_struct->modz == 1)
		nbr = (size_t)va_arg(m_struct->vap, void*);
	else
		nbr = (unsigned int)(va_arg(m_struct->vap, uintmax_t));
	return (nbr);
}

uintmax_t	ft_process_lenmod_unsigned_big(t_printf *m_struct)
{
	uintmax_t	nbr;

	if (m_struct->modhh == 1 || m_struct->modh == 1 ||
		m_struct->modl == 1 || m_struct->nomod == 1)
		return (unsigned long)va_arg(m_struct->vap, void*);
	else if (m_struct->modll == 1)
		nbr = (unsigned long long)va_arg(m_struct->vap, void*);
	else if (m_struct->modj == 1)
		nbr = (uintmax_t)va_arg(m_struct->vap, void*);
	else if (m_struct->modz == 1)
		nbr = (size_t)va_arg(m_struct->vap, void*);
	else
		nbr = (uintmax_t)(va_arg(m_struct->vap, uintmax_t));
	return (nbr);
}

void		ft_unsigned_numbers(char c, t_printf *m_struct)
{
	uintmax_t	nbr;

	nbr = ft_process_lenmod_unsigned(c, m_struct);
	if (m_struct->flaghtag == 1 && (c == 'x' || c == 'X'))
		ft_process_hexa(m_struct, nbr, c);
	else if (m_struct->flaghtag == 1 && (c == 'o' || c == 'O'))
		m_struct->flaghtag = 3;
	if (nbr != 0 && (c != 'u' || c != 'U'))
		m_struct->buffer = conv_hexa(nbr, c);
	if (c == 'u' || c == 'U')
		m_struct->buffer = ft_utoa(nbr);
	if (nbr == 0 && (c != 'u' || c != 'U'))
		m_struct->buffer = ft_strdup("0\0", 0);
	ft_process_octal(m_struct, ft_strlen(m_struct->buffer));
	if (m_struct->flagprecision >= 0 && (m_struct->flagzero = -1))
	{
		ft_process_precision_nbr(m_struct->buffer, m_struct);
		if (nbr == 0 && m_struct->flaghtag == 3)
			ft_place_htag(m_struct->flaghtag, m_struct, 0);
		else if (nbr != 0)
			ft_place_htag(m_struct->flaghtag, m_struct, 0);
	}
	ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
	if (m_struct->flaghtag != 0 && nbr != 0)
		ft_place_htag(m_struct->flaghtag, m_struct, 0);
}

void		ft_process_hexa(t_printf *m_struct, int n, char c)
{
	if (n != 0 && m_struct->flagprecision > 2)
		m_struct->flagprecision += 2;
	m_struct->flaghtag = (c == 'x') ? 1 : 2;
}

void		ft_process_octal(t_printf *m_struct, int len)
{
	if (m_struct->flaghtag == 3)
	{
		if (m_struct->flaghtag == 3 && m_struct->flagzero != -1)
			m_struct->flaghtag = 0;
		if (m_struct->flagprecision > 0 && m_struct->flaghtag == 3)
			m_struct->flaghtag = 0;
		if (m_struct->flagprecision == 0 && m_struct->flaghtag == 3)
		{
			m_struct->flaghtag = 3;
			m_struct->flagprecision = -1;
		}
		if (m_struct->flagprecision == 0 && m_struct->flagzero > 0)
		{
			m_struct->flagprecision = len - 1;
			m_struct->flagzero = -1;
			m_struct->flaghtag = 0;
		}
	}
}
