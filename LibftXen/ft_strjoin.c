/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:35:28 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/10 15:47:16 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	char	*str;

	str = NULL;
	if (!s1 && !s2)
	{
		return (str);
	}
	c = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_strnew(c, '\0');
	if (!str)
		return (NULL);
	c = 0;
	str = ft_strcpy(str, s1);
	str = ft_strncat(str, s2, ft_strlen(s2));
	return (str);
}
