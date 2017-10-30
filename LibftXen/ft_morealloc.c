/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morealloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:07:17 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/10 15:49:53 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_morealloc(char *src, int n, int where)
{
	char	*cpy;
	int		len;

	cpy = NULL;
	len = ft_strlen(src);
	if (where == 1)
	{
		cpy = ft_memalloc((sizeof(char) * (len + n + 1)), ' ');
		cpy[len + n] = '\0';
	}
	else if (where == 2)
	{
		cpy = ft_memalloc((sizeof(char) * (len + (n * 2) + 1)), ' ');
		cpy[len + (n * 2)] = '\0';
	}
	ft_strcpy(&cpy[n], src);
	free(src);
	return (cpy);
}
