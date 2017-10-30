/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:23:56 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/10 15:49:01 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append(char *s1, char *s2, int b)
{
	int		c;
	char	*str;

	str = NULL;
	if (!s1 && !s2)
		return (str);
	c = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_strnew(c, '\0');
	if (!str)
		return (NULL);
	c = 0;
	str = ft_strcpy(str, s1);
	str = ft_strncat(str, s2, ft_strlen(s2));
	if (b == 1)
		free(s1);
	if (b == 2)
		free(s2);
	if (b == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
