/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:17:07 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/09 18:02:01 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		c;
	int		tmp;
	int		neg;

	c = 0;
	neg = 1;
	tmp = 0;
	while ((str[c] > 8 && str[c] < 14) || str[c] == 32)
		c++;
	if (str[c] == '-')
		neg = -1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	while (str[c] > 47 && str[c] < 58 && str[c])
	{
		tmp = (tmp * 10) + (str[c] - 48);
		c++;
	}
	if (neg < 0)
		return (neg * tmp);
	return (tmp);
}
