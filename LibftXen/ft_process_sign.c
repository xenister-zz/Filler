/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:28:46 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 10:36:57 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_place_sign_pres(int sign, t_printf *m_struct)
{
	if (sign != 0)
	{
		if (sign == -1)
			m_struct->buffer = ft_append("-", m_struct->buffer, 2);
		else if (sign == 1)
			m_struct->buffer = ft_append("+", m_struct->buffer, 2);
	}
	m_struct->flagplus = 0;
}

void	ft_sign_zero(int sign, t_printf *m_struct)
{
	int		i;

	if (!(i = 0) && sign != 0)
	{
		if ((sign == 1) && ft_strcmp("0", m_struct->buffer) == 0)
		{
			m_struct->buffer = ft_append("+", m_struct->buffer, 2);
			m_struct->flagplus = 0;
			return ;
		}
		if ((sign == -1) && ft_strcmp("0", m_struct->buffer) == 0)
		{
			m_struct->flagplus = 0;
			return ;
		}
		while (m_struct->buffer[i] == ' ' && m_struct->buffer[i])
			i++;
		if (i > 0 && ft_strcmp("0", &m_struct->buffer[i]) == 0 && sign == 1)
			m_struct->buffer[--i] = '+';
		else if (ft_strlen(m_struct->buffer) > 0 &&
			ft_isallsame(m_struct->buffer, '0') == 1 &&
				sign == 1)
			(m_struct->buffer[0] = '+')
			&& (m_struct->flagplus = 0);
	}
}

void	ft_place_sign(int sign, t_printf *m_struct, int i)
{
	ft_sign_zero(sign, m_struct);
	if (sign != 0 && m_struct->flagplus != 0)
	{
		while (m_struct->buffer[i] == ' ' && m_struct->buffer[i])
			i++;
		if (m_struct->buffer[i] == '0')
			m_struct->buffer[i] = (sign < 0) ? '-' : '+';
		else if (i > 0 && ft_isalldigit(&m_struct->buffer[i]))
			m_struct->buffer[i - 1] = (sign < 0) ? '-' : '+';
		else if (ft_isalldigit(m_struct->buffer))
		{
			m_struct->buffer = ft_morealloc(m_struct->buffer, 1, 1);
			m_struct->buffer[i] = (sign < 0) ? '-' : '+';
		}
		else if (i == 0 && (m_struct->buffer[i] >= '1' &&
			m_struct->buffer[i] <= '9'))
		{
			if (sign == -1)
				m_struct->buffer = ft_append("-", m_struct->buffer, 2);
			else
				m_struct->buffer = ft_append("+", m_struct->buffer, 2);
		}
	}
	m_struct->flagplus = 0;
}
