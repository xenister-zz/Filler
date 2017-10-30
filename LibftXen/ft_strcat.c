/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:42:58 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 15:11:58 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int		c;
	int		d;

	d = 0;
	c = ft_strlen(dst);
	while (src[d])
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (dst);
}
