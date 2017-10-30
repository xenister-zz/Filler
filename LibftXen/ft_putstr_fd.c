/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:16:09 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/15 15:01:23 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		cpt;

	cpt = 0;
	if (!s)
		return ;
	while (s[cpt])
	{
		ft_putchar_fd(s[cpt], fd);
		cpt++;
	}
}
