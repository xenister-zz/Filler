/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:44:59 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/07 18:29:42 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_finder(const char *str, char c)
{
	int		d;
	int		find;

	d = 0;
	find = 0;
	while (str[d])
	{
		if (d == 0 && str[d] != c)
			find++;
		if (c == str[d] && c != str[d + 1] && str[d + 1] != '\0')
			find++;
		d++;
	}
	return (find);
}
