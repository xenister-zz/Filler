/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision_flag.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:24:19 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 10:36:21 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_flag_str(int lenstr, t_printf *m_struct)
{
	char	*buff;
	int		len;

	buff = NULL;
	if (m_struct->flagplus != 0 && m_struct->flagminus == 1)
		m_struct->lm--;
	if (m_struct->lm >= lenstr)
	{
		len = m_struct->lm >= lenstr ? m_struct->lm : lenstr;
		if (!(buff = (char*)ft_memalloc((sizeof(char) * (len + 1)), ' ')))
			return ;
		buff[len] = '\0';
		if (m_struct->flagminus == 0 && m_struct->flagzero != -1)
		{
			ft_str_fill_nchar_rl(buff, '0', m_struct->flagzero);
			m_struct->buffer = ft_place_in_str(buff, m_struct->buffer, 1, 1);
		}
		else if (m_struct->flagminus == 1)
			m_struct->buffer = ft_place_in_str(buff, m_struct->buffer, 0, 1);
		else
			m_struct->buffer = ft_place_in_str(buff, m_struct->buffer, 1, 1);
	}
}

void	ft_process_precision_str(char *str, char c, t_printf *m_struct)
{
	int		lenstr;

	lenstr = ft_strlen(str);
	if (m_struct->flagprecision >= lenstr)
		m_struct->buffer = str;
	else if (m_struct->flagprecision == 0 && (c == 'c' || c == 'C'))
	{
		m_struct->flagprecision = 1;
		m_struct->buffer = ft_strsub(str, 0, m_struct->flagprecision);
		if (str)
			free(str);
	}
	else if (m_struct->flagprecision == 0 && (c != 'c' || c != 'C'))
	{
		m_struct->buffer = ft_strsub(str, 0, 0);
		if (str)
			free(str);
	}
	else
	{
		m_struct->buffer = ft_strsub(str, 0, m_struct->flagprecision);
		if (str)
			free(str);
	}
}

void	ft_process_precision_nbr(char *str, t_printf *m_struct)
{
	int		lenstr;
	int		sizeprecision;

	lenstr = ft_strlen(str);
	if (m_struct->flagprecision == 0 && m_struct->buffer[0] == '0')
	{
		if (m_struct->buffer)
			free(m_struct->buffer);
		m_struct->buffer = ft_strdup("", 0);
	}
	else if (m_struct->flagprecision > lenstr)
	{
		m_struct->buffer = ft_memalloc((sizeof(char) *
			(m_struct->flagprecision + 1)), ' ');
		m_struct->buffer[m_struct->flagprecision] = '\0';
		sizeprecision = m_struct->flagprecision - lenstr;
		ft_str_fill_nchar_lr(m_struct->buffer, '0', sizeprecision);
		ft_place_in_str(&(m_struct->buffer[sizeprecision]), str, 0, 1);
		ft_place_sign_pres(m_struct->flagplus, m_struct);
	}
	else if (m_struct->flagprecision <= lenstr)
	{
		m_struct->buffer = str;
		ft_place_sign(m_struct->flagplus, m_struct, 0);
	}
}
