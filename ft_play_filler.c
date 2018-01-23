/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/23 18:39:45 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int		if_valide(int y, int x, t_info *info)
{
	y = y - MY;
	x = x - MX;
	if (!(IBOARD[IY + y]) || !(IBOARD[IY + y][IX + x]))
		return (0);
	if (IBOARD[IY + y][IX + x] == IE)
		return (0);
	if (IBOARD[IY + y][IX + x] == IP)
	{
		info->okcount++;
		SCORE += 46;
		return(1);
	}
	if (IBOARD[IY + y][IX + x] == '.' || IBOARD[IY + y][IX + x] == '@' || 
			IBOARD[IY + y][IX + x] == '<' || IBOARD[IY + y][IX + x] == '[')
	{  
		SCORE += IBOARD[IY + y][IX + x];
		return (1);
	}
	return (0);
}

int		check_piece_pos(t_info *info)
{
	int		x;
	int		y;
	int		nbpiece;

	y = 0;
	nbpiece = 0;
	info->ok = 1;
	info->okcount = 0;
	SCORE = 0;
	while (IPIECE[y])
		nbpiece += ft_count_char(IPIECE[y++], '*');
	y = -1;
	while (IPIECE[++y] && (nbpiece > 0) && (x = -1))
	{
		while (IPIECE[y][++x] && (nbpiece > 0))
		{
			if (MAR == 0 && (IPIECE[y][x] == '*') && (MAR = 1))
			{
				MX = x;
				MY = y;
			}
			if ((IPIECE[y][x] == '*') && (nbpiece--) && ((if_valide(y, x, info) != 1)))
				return (0);
		}
	}
	if (info->okcount != 1)
		return (0);
	return(1);
}

int		play_filler(int fdr, t_info *info)
{
	int		i;
	
	i = 0;
	init_struct(info);
	chauffage_enemy(info);
	chauffage_border(info);
	while ((IBOARD) && IBOARD[IY])
	{
		IX = 0;
		while ((IBOARD) && IBOARD[IY][IX])
		{
			if (check_piece_pos(info) == 1)
			{
				if ((SCORE >= F_SCORE) && (info->okcount == 1))
					ft_set_score(info);
			}
			if ((F_SCORE == 0) && ((IY == SZBOARDY - 1) && (IX == SZBOARDX - 1)))
			{
				return(2);
			}
			IX++;
		}
		IY++;
	}
	return(1);
}
