/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:04:36 by susivagn          #+#    #+#             */
/*   Updated: 2017/02/14 14:26:18 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strintlen(intmax_t nbr)
{
	int		size;

	size = 1;
	while ((nbr / 10) != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}
