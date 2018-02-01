/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/01 07:03:33 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LibftXen/ft_printf.h"
#include "./filler.h"

void	ft_set_score(t_info *info)
{
	if (info->plateau != 1 || SCORE > F_SCORE)
	{
		F_SCORE = SCORE;
		SCORE = 0;
		SY = IY;
		SX = IX;
	}
	else if (info->plateau == 1 && SCORE == F_SCORE)
		SCORE = 0;
}

void	init_struct(t_info *info)
{
	IY = 0;
	info->margin = 0;
	SCORE = 0;
	F_SCORE = 0;
	SY = 0;
	SX = 0;
}

int		main(void)
{
	int		i;
	t_info	*info;

	info = ft_memalloc(sizeof(t_info), 0);
	IP = 0;
	F_SCORE = 0;
	SCORE = 0;
	while (1)
	{
		filler_read(info);
		i = play_filler(info);
		if (i == 2 && F_SCORE == 0)
			break ;
		if (F_SCORE != 0)
			ft_printf("%d %d\n", (SY - MY), (SX - MX));
		free_board(info, IBOARD, SZBOARDY);
		free_tab(IPIECE, SZPIECEY);
		IBOARD = NULL;
		IPIECE = NULL;
	}
	free_board(info, IBOARD, SZBOARDY);
	free_tab(IPIECE, SZPIECEY);
	ft_bzero(info, sizeof(t_info));
	free(info);
	return (0);
}
