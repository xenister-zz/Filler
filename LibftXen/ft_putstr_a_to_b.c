/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:55:13 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:07:49 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_a_to_b(char *str, char a, char b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != a)
		j++;
	if (!str[j])
		return (0);
	i = ++j;
	while (str[i] && str[i] != b)
	{
		ft_putunicode(str[i]);
		i++;
	}
	return (i - j);
}
