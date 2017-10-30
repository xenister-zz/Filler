/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:57:38 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 16:29:52 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		a;

	a = ft_strlen(src);
	while (a >= 0)
	{
		if (src[a] == ((char)c))
			return (&((char*)src)[a]);
		if (((char)c) == '\0')
			return (&((char*)src)[a + 1]);
		a--;
	}
	return (0);
}
