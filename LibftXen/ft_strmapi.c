/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:38:54 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/21 19:48:24 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	char	*copy;

	c = 0;
	if (!s)
		return (((char*)s));
	copy = ft_strdup(((char*)s), 0);
	if (!copy)
		return (copy);
	while (copy[c])
	{
		copy[c] = f(c, s[c]);
		c++;
	}
	return (copy);
}
