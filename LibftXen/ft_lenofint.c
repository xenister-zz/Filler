/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenofint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:12:43 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/14 20:07:03 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenofint(int n)
{
	long	c;
	long	nbr;
	long	divis;

	c = 1;
	nbr = n;
	divis = 1;
	if (nbr < 0)
	{
		nbr = n * (-1);
		c++;
	}
	if (nbr < 10)
		return (c);
	if (nbr / divis == 0)
	{
		c++;
		return (c);
	}
	while (nbr / divis > 9)
	{
		divis = divis * 10;
		c++;
	}
	return (c);
}
