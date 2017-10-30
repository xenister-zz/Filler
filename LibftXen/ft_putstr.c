/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:11:50 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/22 16:05:07 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *str)
{
	int		c;

	c = 0;
	if (!str)
		return (0);
	while (str[c])
	{
		ft_putchar(str[c]);
		c++;
	}
	return (c);
}
