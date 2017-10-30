/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:27:45 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/22 19:21:11 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src, int freesrc)
{
	size_t	a;
	char	*dst;

	if (!src)
		return (ft_strdup("(null)", 0));
	dst = NULL;
	a = ft_strlen(src);
	if (!(dst = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (src[a])
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	if (freesrc == 1)
		free(src);
	return (dst);
}
