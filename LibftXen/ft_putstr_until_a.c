/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_until_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:12:42 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:08:06 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_until_a(char *str, char a)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != a)
	{
		ft_putunicode(str[i]);
		i++;
	}
	return (i);
}
