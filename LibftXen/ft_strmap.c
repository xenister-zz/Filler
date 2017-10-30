/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:13:30 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/21 19:48:18 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		copy[c] = f(s[c]);
		c++;
	}
	return (copy);
}
