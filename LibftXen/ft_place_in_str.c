/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_in_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:33:29 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/27 10:29:16 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_place_in_str(char *dst, char *src, int a, int b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (a == 0)
		while (src[i] && dst[i])
		{
			dst[i] = src[i];
			i++;
		}
	if (a == 1)
	{
		i = ft_strlen(dst);
		j = ft_strlen(src);
		while (j >= 0 && i >= 0)
		{
			dst[i] = src[j];
			i--;
			j--;
		}
	}
	if (b == 1)
		free(src);
	return (dst);
}
