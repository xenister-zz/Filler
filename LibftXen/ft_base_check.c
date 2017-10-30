/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:22:28 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 15:19:14 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_base_check(char *str)
{
	int		i;
	int		j;

	j = 0;
	if (!str)
		return (0);
	while (str[j])
	{
		i = j + 1;
		while (str[i])
		{
			if (str[j] == str[i] || str[i] == '-' || str[i] == '+')
				return (0);
			i++;
		}
		j++;
	}
	if (j < 1 || (j == 1 && !str[j]))
		return (0);
	return (j);
}
