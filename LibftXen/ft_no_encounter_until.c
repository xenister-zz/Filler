/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_encounter_until.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:05:59 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/17 15:18:00 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_no_encounter_until(char *str, char *caras, char c)
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
			return (0);
		i++;
	}
	return (1);
}
