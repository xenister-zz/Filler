/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:57:49 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 16:50:12 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (((UC*)s1)[c] == ((UC*)s2)[c] && ((UC*)s1)[c] && ((UC*)s2)[c]
		&& c < (n - 1))
		c++;
	if (n == 0)
		return (0);
	return (((UC*)s1)[c] - ((UC*)s2)[c]);
}
