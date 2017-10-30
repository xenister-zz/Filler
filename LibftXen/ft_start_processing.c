/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:42:34 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 10:37:36 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_start_processing(char c, t_printf *m_struct)
{
	if (m_struct->flagwidth != 0 || m_struct->flagzero != -1)
		m_struct->lm = m_struct->flagwidth >= m_struct->flagzero ?
			m_struct->flagwidth : m_struct->flagzero;
	if (c == 's' || c == 'S' || c == 'c' || c == 'C' || c == '%')
		ft_string_char(c, m_struct);
	if (c == 'd' || c == 'i' || c == 'D')
		ft_signed_numbers(c, m_struct);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		ft_unsigned_numbers(c, m_struct);
	if (c == 'p')
		ft_print_adress(m_struct);
	return (0);
}

void	ft_print_adress(t_printf *m_struct)
{
	unsigned long	addr;

	if (!(addr = (unsigned long)va_arg(m_struct->vap, void*)))
	{
		m_struct->buffer = ft_strdup("0x0", 0);
		ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
		return ;
	}
	m_struct->buffer = ft_itoa_base(addr, "0123456789abcdef");
	m_struct->buffer = ft_append("0x", m_struct->buffer, 2);
	ft_process_flag_str(ft_strlen(m_struct->buffer), m_struct);
}

int		ft_check_space(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
	{
		j++;
		i++;
	}
	return (j);
}
