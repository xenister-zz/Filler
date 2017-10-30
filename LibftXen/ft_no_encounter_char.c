/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_encounter_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:50:24 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 14:59:50 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_no_encounter_char(char *str, char *caras, char c)
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
			return (str[i]);
		i++;
	}
	return (0);
}
