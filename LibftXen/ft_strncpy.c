/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:54:32 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 14:18:53 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	c;

	c = 0;
	while (src[c] && c < len)
	{
		dst[c] = src[c];
		c++;
	}
	while (c < len)
	{
		dst[c] = '\0';
		c++;
	}
	return (dst);
}
