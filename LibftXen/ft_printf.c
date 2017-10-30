/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:19:19 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 11:27:10 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *arg, ...)
{
	t_printf	m_struct;

	ft_bzero(&m_struct, sizeof(t_printf));
	if (!arg)
		return (0);
	if (!(ft_strchr(arg, '%')))
		ft_noflags(arg, &m_struct);
	else
	{
		va_start(m_struct.vap, arg);
		m_struct.len += ft_putstr_until_a(arg, '%');
		ft_starter_with_flags(arg, &m_struct);
	}
	return (m_struct.len);
}

void	ft_noflags(char *arg, t_printf *m_struct)
{
	int		i;

	i = 0;
	while (arg[i])
		m_struct->len += ft_putunicode(arg[i++]);
}

char	*conv_hexa(uintmax_t nbr, char c)
{
	if (c == 'x')
		return (ft_itoa_base(nbr, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_itoa_base(nbr, "0123456789ABCDEF"));
	else if (c == 'o' || c == 'O')
		return (ft_itoa_base(nbr, "01234567"));
	return (NULL);
}

void	init_struct_flag_lenmod(t_printf *m_struct)
{
	m_struct->flagminus = 0;
	m_struct->flagplus = 0;
	m_struct->flaghtag = 0;
	m_struct->flagspace = 0;
	m_struct->flagprecision = -1;
	m_struct->flagzero = -1;
	m_struct->flagwidth = 0;
	m_struct->lm = 0;
	m_struct->nomod = 0;
	m_struct->modhh = 0;
	m_struct->modh = 0;
	m_struct->modll = 0;
	m_struct->modl = 0;
	m_struct->modj = 0;
	m_struct->modz = 0;
}

void	ft_set_init_flag(t_printf *m_struct)
{
	m_struct->flagminus = 0;
	m_struct->flagplus = 0;
	m_struct->flaghtag = 0;
	m_struct->flagspace = 0;
	m_struct->flagprecision = -1;
	if (m_struct->flagwidth != 0 || m_struct->flagzero != -1)
		m_struct->lm = m_struct->flagwidth >= m_struct->flagzero ?
			m_struct->flagwidth : m_struct->flagzero;
}
