/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:01:59 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/10 15:45:49 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	c;
	char			*cpy;

	c = 0;
	if (!s)
		return (((char*)s));
	cpy = ft_strnew(len, '\0');
	if (!cpy)
		return (NULL);
	while (c < ((UI)len))
	{
		cpy[c] = s[start];
		c++;
		start++;
	}
	cpy[c] = '\0';
	return (cpy);
}
