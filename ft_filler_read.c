/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/01 01:58:32 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void	get_player(char *line, t_info *info)
{
	if (ft_strstr(line, "p1"))
	{
		info->player = 'O';
		info->enemy = 'X';
	}
	else
	{
		info->player = 'X';
		info->enemy = 'O';
	}
	free(line);
}

void	get_board(int fd, char *line, t_info *info)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	info->plateau = 0;
	SZBOARDY = ft_atoi(&line[8]);
	if (SZBOARDY == 15)
		info->plateau = 1;
	SZBOARDX = ft_atoi(&line[11]);
	free(line);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strstr(line, "    012"))
			free(line);
		else if (line[0] == '0')
		{
			info->board = ft_addchartable(info->board, line + 4,
				SZBOARDY + 1);
			i++;
		}
		if (i == SZBOARDY)
		{
			info->board = ft_addchartable(info->board,
				ft_memalloc(SZBOARDX + 1, '\0'), (SZBOARDY + 1));
			break ;
		}
	}
}

void	get_piece(int fd, char *line, t_info *info)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	info->piece_sizey = ft_atoi(&line[6]);
	info->piece_sizex = ft_atoi(&line[8]);
	free(line);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((line[0] == '.') || (line[0] == '*'))
		{
			info->piece = ft_addchartable(info->piece, line,
				SZBOARDY);
			i++;
		}
		if (i == SZPIECEY)
			break ;
	}
}

int		filler_read(int fdr, t_info *info)
{
	int		ret;
	char	*line;

	ret = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		dprintf(info->fds, "RET == *%d*\n", ret);
		dprintf(info->fds, "*%s*\n", line);
		if (IP == 0)
			get_player(line, info);
		else if (ft_strstr(line, "Plateau"))
			get_board(0, line, info);
		else if (ft_strstr(line, "Piece"))
		{
			get_piece(0, line, info);
			break ;
		}
	}
	return (0);
}
