/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_encounter_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:29:00 by susivagn          #+#    #+#             */
/*   Updated: 2017/09/18 18:31:54 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_no_encounter_index(char *str, char *caras)
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
			return (i);
		i++;
	}
	return (0);
}
