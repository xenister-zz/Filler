/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:16:42 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 17:08:12 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitter(char **dest, char const *src, char c)
{
	int		d;
	int		a;
	int		cpt;

	d = -1;
	a = 0;
	while (src[++d])
	{
		if (src[d + 1] == '\0')
		{
			dest[a] = 0;
			return (dest);
		}
		if ((c == src[d] && c != src[d + 1]) || (d == 0 && src[d] != c))
		{
			cpt = 0;
			if (d != 0 && src[d] == c)
				d = d + 1;
			cpt = ft_lenbeforec(&src[d + 1], c);
			dest[a++] = ft_strsub(src, d, cpt);
			d = d + (cpt - 1);
		}
	}
	dest[a] = 0;
	return (dest);
}
