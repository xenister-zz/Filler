/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_encounter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:50:24 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/21 15:21:11 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_no_encounter(char *str, char *caras)
{
	int		i;
	int		j;
	int		ya;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		ya = 0;
		while (caras[j])
		{
			if (str[i] == caras[j])
				ya = 1;
			j++;
		}
		if (ya == 0)
			return (0);
		i++;
	}
	return (1);
}
