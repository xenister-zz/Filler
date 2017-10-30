/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_htag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:26:19 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 10:33:56 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_place_htag_pres(int sign, t_printf *m_struct)
{
	if (ft_isallhexa(m_struct->buffer))
	{
		if (m_struct->buffer[0] == '0' && m_struct->buffer[1] == '0')
		{
			if (sign == 1)
				m_struct->buffer = ft_append("0x", m_struct->buffer, 2);
			if (sign == 2)
				m_struct->buffer = ft_append("0X", m_struct->buffer, 2);
			if (sign == 3)
				return ;
		}
		else if (sign != 3 && m_struct->buffer[0] == '0' &&
			m_struct->buffer[1] != '0' && m_struct->buffer[1] != '\0')
			m_struct->buffer = ft_append("0", m_struct->buffer, 2);
		else if (sign == 1)
			m_struct->buffer = ft_append("0x", m_struct->buffer, 2);
		else if (sign == 2)
			m_struct->buffer = ft_append("0X", m_struct->buffer, 2);
		else if (sign == 3)
			m_struct->buffer = ft_append("0", m_struct->buffer, 2);
	}
	m_struct->flaghtag = 0;
}

void	ft_place_htag(int sign, t_printf *m_struct, int i)
{
	while (m_struct->buffer[i] && m_struct->buffer[i] == ' ')
		i++;
	if (m_struct->buffer[i] == '0' && m_struct->buffer[i + 1] == '0' &&
		(sign == 1 || sign == 2))
		m_struct->buffer[i + 1] = (sign == 1) ? 'x' : 'X';
	else if (i > 0 && sign == 3)
		m_struct->buffer[i - 1] = '0';
	else if (i > 1 && (sign == 1 || sign == 2))
	{
		m_struct->buffer[i - 2] = '0';
		m_struct->buffer[i - 1] = (sign == 1) ? 'x' : 'X';
	}
	else if (ft_isallhexa(m_struct->buffer))
	{
		if (sign == 1)
			m_struct->buffer = ft_append("0x", m_struct->buffer, 2);
		if (sign == 2)
			m_struct->buffer = ft_append("0X", m_struct->buffer, 2);
		if (sign == 3)
			m_struct->buffer = ft_append("0", m_struct->buffer, 2);
	}
	else if (m_struct->buffer[i] != '0' || m_struct->buffer[i] != ' ')
		ft_put_htag_space_after(sign, m_struct);
}

void	ft_put_htag_space_after(int sign, t_printf *m_struct)
{
	int		i;
	int		j;

	i = ft_strlen(m_struct->buffer);
	j = ft_count_char(m_struct->buffer, ' ');
	if (sign == 3 && i > 1)
	{
		m_struct->buffer[i - 1] = '\0';
		m_struct->buffer = ft_append("0", m_struct->buffer, 2);
	}
	else if (sign == 3 && i <= 1)
	{
		m_struct->buffer[i] = '\0';
		m_struct->buffer = ft_append("0", m_struct->buffer, 2);
	}
	if (sign != 3 && j > 1)
	{
		m_struct->buffer[i - 1] = '\0';
		m_struct->buffer[i - 2] = '\0';
		if (sign == 1)
			m_struct->buffer = ft_append("0x", m_struct->buffer, 2);
		if (sign == 2)
			m_struct->buffer = ft_append("0X", m_struct->buffer, 2);
	}
}
