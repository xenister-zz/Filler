/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:05:02 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 16:07:51 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putunicodesup(int c)
{
	char	u;

	if ((c >= 0x800) && (c < 0x10000))
	{
		u = (c >> 12) + 0xE0;
		write(1, &u, 1);
		u = ((c >> 6) & 0x3F) + 0x80;
		write(1, &u, 1);
		u = (c & 0x3F) + 0x80;
		write(1, &u, 1);
		return (3);
	}
	else if ((c >= 0x10000) && (c <= 0x10FFFF))
	{
		u = (c >> 18) + 0xF0;
		write(1, &u, 1);
		u = ((c >> 12) & 0x3F) + 0x80;
		write(1, &u, 1);
		u = ((c >> 6) & 0x3F) + 0x80;
		write(1, &u, 1);
		u = (c & 0x3F) + 0x80;
		write(1, &u, 1);
		return (4);
	}
	return (0);
}

int		ft_putunicode(int c)
{
	char	u;

	if (c < 0x80)
	{
		write(1, &c, 1);
		return (1);
	}
	else if ((c >= 0x80) && (c < 0x800))
	{
		u = (c >> 6) + 0xC0;
		write(1, &u, 1);
		u = (c & 0x3F) + 0x80;
		write(1, &u, 1);
		return (2);
	}
	else if (c >= 0x800)
		return (ft_putunicodesup(c));
	return (0);
}
