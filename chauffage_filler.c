/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chauffage_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:01:29 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/01 03:45:28 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int		chauffage_border(t_info *info)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	c = '<';
	if (info->plateau != 1)
	{
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
	}
	if (info->plateau == 1 && info->player == 'O')
		chauffage_map00(info, 0);
	return (0);
}

int		chauffage_map00(t_info *info, int x)
{
	char	c;

	c = '[';
	dprintf(info->fds, "START STRAT PLATEAU %d\n", info->plateau);
	while (IBOARD[8][x])
		{
			if (IBOARD[8][x] && IBOARD[8][x] == '.' && x > 2)
				IBOARD[8][x] = c;
			if (IBOARD[7][x] && IBOARD[7][x] == '.' && x > 6)
				IBOARD[7][x] = c;
			x++;
		}
	
	dprintf(info->fds, "END STRAT PLATEAU \n");
	return(0);
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

void	free_board(t_info *info, char **tab, int size)
{
	while (size > 0)
	{
		free(tab[--size] - 4);
	}
	free(tab[SZBOARDY]);
	free(tab);
}

void	free_tab(t_info *info, char **tab, int size)
{
	while (size >= 0)
	{
		free(tab[size]);
		size--;
	}
	free(tab);
}