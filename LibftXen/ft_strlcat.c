/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:23:33 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 19:01:39 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	d;

	c = ft_strlen(dst);
	d = 0;
	if (size <= c)
		return (size + ft_strlen(src));
	if (size == ft_strlen(dst) + 1)
		return (c + ft_strlen(src));
	ft_strncat(dst, src, (size - c - 1));
	return (c + ft_strlen(src));
}
