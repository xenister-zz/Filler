/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:19:22 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 15:40:09 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((UC*)dst)[a] = ((UC*)src)[a];
		if (((UC*)src)[a] == ((UC)c))
			return (&dst[a + 1]);
		a++;
	}
	return (NULL);
}
