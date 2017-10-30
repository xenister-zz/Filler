/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenbeforec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:25:46 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/14 14:30:00 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenbeforec(const char *src, char c)
{
	int		d;
	int		e;

	d = 0;
	e = 1;
	while (src[d] && src[d] != c)
	{
		e++;
		d++;
	}
	return (e);
}
