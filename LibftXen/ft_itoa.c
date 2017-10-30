/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:45:49 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 19:52:37 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t n)
{
	char				*str;
	int					sizemalloc;
	int					sign;
	intmax_t			nbr;

	nbr = n;
	sign = (n < 0) ? 1 : 0;
	sizemalloc = ft_strintlen(n);
	sizemalloc = (n < 0) ? (sizemalloc + 1) : sizemalloc;
	if (!(str = (char*)malloc(sizeof(char) * (sizemalloc + 1))))
		return (NULL);
	nbr = (n > 0) ? -nbr : nbr;
	str[sizemalloc] = '\0';
	while (--sizemalloc >= 0)
	{
		str[sizemalloc] = -(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (sign == 1)
		str[++sizemalloc] = '-';
	return (str);
}
