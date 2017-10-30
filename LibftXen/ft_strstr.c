/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:02:58 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 16:19:34 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		c;
	int		d;
	int		t;

	c = 0;
	d = 0;
	t = 0;
	if (little[d] == '\0')
		return (((char*)big));
	while (big[c])
	{
		d = 0;
		t = c;
		while (big[t] == little[d])
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
