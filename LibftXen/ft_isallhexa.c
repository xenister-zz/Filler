/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isallhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:38:18 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 17:43:25 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isallhexa(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if ((src[i] >= '0' && src[i] <= '9') || (src[i] >= 'A' && src[i] <= 'F')
			|| (src[i] >= 'a' && src[i] <= 'f'))
			i++;
		else
			return (0);
	}
	return (i);
}
