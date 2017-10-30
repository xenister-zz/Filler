/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:32:34 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 12:04:29 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent_chck(char *arg, int i, int l, t_printf *m_struct)
{
	char	c;

	while (arg[i] && i < l)
	{
		while (i < l && arg[i] != '%')
			i++;
		i = (i >= l) ? i : ++i;
		if ((c = ft_encounter(&arg[i], "sSpdDioOuUxXcC%")) == '%')
		{
			init_struct_flag_lenmod(m_struct);
			ft_get_flags(&arg[i], '%', m_struct);
			ft_start_processing('%', m_struct);
			m_struct->len += ft_putstr(m_struct->buffer);
			m_struct->len += ft_putstr_a_to_b(&arg[i], '%', '%');
			while (i < l && arg[i] != '%')
				i++;
			i = (i >= l) ? i : ++i;
			ft_strdel(&m_struct->buffer);
		}
		else
			return (i);
	}
	return (i);
}

int		ft_starter_with_flags(char *arg, t_printf *m_struct)
{
	int		i;
	int		l;
	char	c;

	i = -1;
	l = ft_strlen(arg);
	while (i++ < l)
	{
		i = ft_pourcent_chck(arg, i, l, m_struct);
		if (i >= l)
			return (0);
		c = ft_encounter(&arg[i], "sSpdDioOuUxXcC");
		if ((ft_no_encounter_until(&arg[i], "-+# .0123456789hljz", c)))
		{
			init_struct_flag_lenmod(m_struct);
			ft_get_flags(&arg[i], c, m_struct);
			ft_get_len_mod(&arg[i], c, m_struct);
			ft_start_processing(c, m_struct);
			m_struct->len += ft_putstr(m_struct->buffer);
			ft_strdel(&m_struct->buffer);
		}
		m_struct->len += ft_putstr_a_to_b(&arg[i], c, '%');
	}
	return (0);
}
