/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:02:56 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 16:07:24 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n && n != 0)
	{
		if (((UC*)src)[a] == ((UC)c))
			return (&((UC*)src)[a]);
		a++;
	}
	return (NULL);
}
