/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:51:09 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 14:20:59 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while (((UC*)s1)[c] == ((UC*)s2)[c] && c < n)
	{
		c++;
		if (c == n)
			return (0);
	}
	return (((UC*)s1)[c] - ((UC*)s2)[c]);
}
