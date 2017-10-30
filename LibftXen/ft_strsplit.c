/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:35:30 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/14 15:31:50 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		nbfind;
	int		d;
	char	**splittab;

	d = 0;
	if (!s)
		return (NULL);
	nbfind = ft_finder(s, c);
	splittab = NULL;
	if (ft_finder(s, c) == 0)
		nbfind = 1;
	splittab = malloc(sizeof(char**) * (nbfind + 1));
	if (!splittab)
		return (NULL);
	splittab = ft_splitter(splittab, s, c);
	return (splittab);
}
