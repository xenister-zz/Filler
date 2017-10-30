/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:14:08 by susivagn          #+#    #+#             */
/*   Updated: 2017/03/29 17:47:34 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size, char c)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_memset(mem, c, size);
	return (mem);
}
