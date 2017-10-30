/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:13:56 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 15:21:26 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_width_precision_zero(char *arg, int b, t_printf *m_struct)
{
	int		i;

	i = 0;
	if (b == 0)
	{
		m_struct->flagprecision = ft_atoi(arg);
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
		return (i);
	}
	else if (b == 1)
	{
		m_struct->flagwidth = ft_atoi(arg);
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
		return (i);
	}
	else if (b == 2)
	{
		m_struct->flagzero = ft_atoi(arg);
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
		return (i);
	}
	return (0);
}

void	ft_get_len_mod(char *arg, char c, t_printf *m_struct)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != c)
	{
		if (arg[i] == 'h' && arg[i + 1] == 'h' && (i += 2))
			m_struct->modhh = 1;
		else if (arg[i] == 'h' && (i += 1))
			m_struct->modh = 1;
		else if (arg[i] == 'l' && arg[i + 1] == 'l' && (i += 2))
			m_struct->modll = 1;
		else if (arg[i] == 'l' && (i += 1))
			m_struct->modl = 1;
		else if (arg[i] == 'j' && (i += 1))
			m_struct->modj = 1;
		else if (arg[i] == 'z' && (i += 1))
			m_struct->modz = 1;
		else
			i++;
	}
	if (m_struct->modhh == 0 && m_struct->modh == 0 &&
			m_struct->modll == 0 && m_struct->modl == 0 &&
				m_struct->modj == 0 && m_struct->modz == 0)
		m_struct->nomod = 1;
}

void	ft_get_flags(char *arg, char c, t_printf *m_struct)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != c)
	{
		if (arg[i] == '-' && (i += 1))
			m_struct->flagminus = 1;
		else if (arg[i] == '+' && (i += 1))
			m_struct->flagplus = 1;
		else if (arg[i] == '#' && (i += 1))
			m_struct->flaghtag = 1;
		else if (arg[i] == ' ' && (i += 1))
			m_struct->flagspace = 1;
		else if (arg[i] == '.' && (i += 1))
			i += ft_get_width_precision_zero(&arg[i], 0, m_struct);
		else if (arg[i] == '0' && (i += 1))
			i += ft_get_width_precision_zero(&arg[i], 2, m_struct);
		else if (ft_isnum_no_zero(arg[i]) && m_struct->flagprecision == -1)
			i += ft_get_width_precision_zero(&arg[i], 1, m_struct);
		else
			i++;
	}
}
