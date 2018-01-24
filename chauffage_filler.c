/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chauffage_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:01:29 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/24 12:45:27 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int		chauffage_border(t_info *info)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	if (info->plateau == 1)
		c = '[';
	else
		c = '<';
	while ((IBOARD) && IBOARD[y])
	{
		x = 0;
		while ((IBOARD) && IBOARD[y] && IBOARD[y][x])
		{
			if ((y == 1 || y == (SZBOARDY - 2)) && (IBOARD[y][x] == '.'))
				IBOARD[y][x] = c;
			else if ((x == 1 || x == (SZBOARDX - 2)) && (IBOARD[y][x] == '.'))
				IBOARD[y][x] = c;
			x++;
		}
		y++;
	}
	return (0);
}

int		chauffage_enemy(int x, int y, t_info *info)
{
	while ((IBOARD) && IBOARD[y])
	{
		x = 0;
		while ((IBOARD) && IBOARD[y] && IBOARD[y][x])
		{
			if (IBOARD[y][x] == IE)
			{
				if ((x > 0) && (IBOARD[y][x - 1]) && (IBOARD[y][x - 1] == '.'))
					IBOARD[y][x - 1] = '@';
				else if ((x < SZBOARDX) && (IBOARD[y][x + 1]) &&
						(IBOARD[y][x + 1] == '.'))
					IBOARD[y][x + 1] = '@';
				else if ((y > 0) && (IBOARD[y - 1][x]) &&
						(IBOARD[y - 1][x] == '.'))
					IBOARD[y - 1][x] = '@';
				else if ((y < SZBOARDY) && (IBOARD[y + 1][x]) &&
						(IBOARD[y + 1][x] == '.'))
					IBOARD[y + 1][x] = '@';
			}
			x++;
		}
		y++;
	}
	return (0);
}