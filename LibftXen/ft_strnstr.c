/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:23:33 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 16:35:12 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		c;
	int		d;
	int		t;

	c = 0;
	d = 0;
	t = 0;
	if (little[d] == '\0')
		return (((char*)big));
	while (big[c] && c < ((int)len))
	{
		d = 0;
		t = c;
		while (big[t] == little[d] && t < ((int)len))
		{
			t++;
			d++;
			if (little[d] == '\0')
				return (&((char*)big)[c]);
		}
		c++;
	}
	return (0);
}
