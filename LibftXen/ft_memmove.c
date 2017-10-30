/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:37:20 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 19:12:16 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	c;

	c = len;
	if (src <= dst)
		while (c--)
			((UC*)dst)[c] = ((UC*)src)[c];
	else
	{
		c = 0;
		while (c < len)
		{
			((UC*)dst)[c] = ((UC*)src)[c];
			c++;
		}
	}
	return (dst);
}
