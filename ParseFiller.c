/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/25 14:50:55 by susivagn         ###   ########.fr       */
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
	char	*line;
	int		i;
	t_info	*info;

	info = ft_memalloc(sizeof(t_info), 0);
	//info->fds = open("./patate", O_CREAT | O_RDWR | O_TRUNC, 0666);
	//info->fdd = open("./poundai", O_CREAT | O_RDWR | O_TRUNC, 0666);
	line = NULL;
	IP = 0;
	F_SCORE = 0;
	SCORE = 0;
	while (1)
	{
		filler_read(info->fds, info);
		i = play_filler(info->fds, info);
		if (i == 2 && F_SCORE == 0)
			break ;
		if (F_SCORE != 0)
			ft_printf("%d %d\n", (SY - MY), (SX - MX));
		IBOARD = NULL;
		IPIECE = NULL;
	}
	return (0);
}
