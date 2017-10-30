/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:24:59 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 15:10:15 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	val[10];
	int		c;
	long	nb1;

	c = 0;
	nb1 = n;
	if (nb1 < 0)
	{
		ft_putchar_fd('-', fd);
		nb1 = nb1 * (-1);
	}
	while (nb1 != 0)
	{
		val[c] = '0' + (nb1 % 10);
		nb1 = nb1 / 10;
		c++;
	}
	c--;
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (c >= 0)
	{
		ft_putchar_fd(val[c], fd);
		c--;
	}
}
