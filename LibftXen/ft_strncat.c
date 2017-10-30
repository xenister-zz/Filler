/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:50:37 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 15:12:50 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	c;
	size_t	d;

	c = ft_strlen(dst);
	d = 0;
	while (d < n && src[d])
	{
		dst[c] = src[d];
		d++;
		c++;
	}
	dst[c] = '\0';
	return (dst);
}
