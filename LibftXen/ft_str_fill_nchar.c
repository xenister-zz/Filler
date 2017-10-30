/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fill_nchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:19:51 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 16:05:55 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_fill_nchar_lr(char *str, char c, int n)
{
	int		i;

	i = 0;
	while (str[i] && i < n)
	{
		str[i] = c;
		i++;
	}
	if (i == n && str[i] != '\0')
		while (str[i])
		{
			str[i] = ' ';
			i++;
		}
}

void	ft_str_fill_nchar_rl(char *str, char c, int n)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	i--;
	while (i >= 0 && j < n)
	{
		str[i] = c;
		i--;
		j++;
	}
	if (j == n && i != 0)
		while (i >= 0)
		{
			str[i] = ' ';
			i--;
		}
}
