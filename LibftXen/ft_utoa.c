/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:29:47 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 20:03:44 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_struintlen(uintmax_t nbr)
{
	int		size;

	size = 1;
	while ((nbr / 10) != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

char	*ft_utoa(uintmax_t n)
{
	char				*str;
	int					sizemalloc;
	uintmax_t			nbr;

	nbr = n;
	sizemalloc = ft_struintlen(n);
	if (!(str = (char*)malloc(sizeof(char) * (sizemalloc + 1))))
		return (NULL);
	str[sizemalloc] = '\0';
	sizemalloc--;
	while (sizemalloc != 0)
	{
		str[sizemalloc] = (nbr % 10) + '0';
		nbr = nbr / 10;
		sizemalloc--;
	}
	str[sizemalloc] = '0' + nbr;
	return (str);
}
