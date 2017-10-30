/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_encounter_until_index.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:17:42 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/17 18:05:55 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_no_encounter_until_index(char *str, char *caras, char c)
{
	int		i;
	int		j;
	int		ya;

	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
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
			return (-i);
		i++;
	}
	return (i);
}
