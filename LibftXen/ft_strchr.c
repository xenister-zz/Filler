/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:50:32 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 16:17:42 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int		a;

	a = 0;
	while (src[a])
	{
		if (src[a] == ((char)c))
			return (&((char*)src)[a]);
		a++;
	}
	if (src[a] == ((char)c))
		return (&((char*)src)[a]);
	return (0);
}
