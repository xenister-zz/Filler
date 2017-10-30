/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:18:17 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 15:20:11 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t nbr, char *base)
{
	char			*nb;
	int				len;
	int				lencpy;
	uintmax_t		cpnbr;
	int				ilen;

	ilen = 0;
	cpnbr = nbr;
	if (!base || !(len = ft_base_check(base)))
		return (0);
	while (cpnbr && ++ilen)
		cpnbr = cpnbr / len;
	if (!(nb = (char *)malloc(sizeof(char) * ilen + 1)))
		return (0);
	lencpy = len;
	nb[ilen] = '\0';
	while (nbr)
	{
		nb[--ilen] = (base[nbr % lencpy]);
		nbr = nbr / lencpy;
	}
	return (nb);
}
