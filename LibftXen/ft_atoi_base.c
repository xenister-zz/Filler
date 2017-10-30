/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:40:53 by susivagn          #+#    #+#             */
/*   Updated: 2017/01/16 18:24:40 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, char *base)
{
	int		nb;
	int		len;
	int		c;

	nb = 0;
	c = 0;
	if (!str || !base || !(len = ft_base_check(base)))
		return (0);
	while ((str[c] > 8 && str[c] < 14) || str[c] == 32)
		str++;
	if (str[c] == '+' || str[c] == '-')
		str++;
	while (str[c])
		if (!(ft_strchr(base, str[c++])))
			return (0);
	c = 0;
	while (str[c])
		nb = (nb * len) + (ft_strchr(base, str[c++]) - base);
	return (nb);
}
