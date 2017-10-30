/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:07:06 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/14 17:53:22 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char	val[10];
	int		c;
	long	nb1;

	c = 0;
	nb1 = nb;
	if (nb1 < 0)
	{
		ft_putchar('-');
		nb1 = nb1 * (-1);
	}
	while (nb1 != 0)
	{
		val[c] = '0' + (nb1 % 10);
		nb1 = nb1 / 10;
		c++;
	}
	c--;
	if (nb == 0)
		ft_putchar('0');
	while (c >= 0)
	{
		ft_putchar(val[c]);
		c--;
	}
}
