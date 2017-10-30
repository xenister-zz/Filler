/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:53:15 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/08 15:08:17 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_size_unicode(int c)
{
	int		taille;

	taille = 0;
	if (c < 0x80)
		taille = 1;
	else if ((c >= 0x80) && (c < 0x800))
		taille = 2;
	else if ((c >= 0x800) && (c < 0x10000))
		taille = 3;
	else if ((c >= 0x10000) && (c <= 0x10FFFF))
		taille = 4;
	return (taille);
}
