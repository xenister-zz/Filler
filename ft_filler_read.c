/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/18 19:24:02 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void    get_player(char *line, t_info *info)
{
    dprintf(info->fds, "*********************************\n");
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
    dprintf(info->fds, "players ================== %c\n", info->player);
    dprintf(info->fds, "enemy ================== %c\n", info->enemy);
}

void    get_board(int fd, char *line, t_info *info)
{
    int ret;
    int i;
    

    ret = 0;
    i = 0;
    dprintf(info->fds, "-----------------------------------------\n");
    SZBOARDY = ft_atoi(&line[8]);
    SZBOARDX = ft_atoi(&line[11]);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (line[0] == '0')
        {
            info->board = ft_addchartable(info->board, &line[4], SZBOARDY + 1);
            i++;
        }
        if (i == SZBOARDY)
        {
            info->board = ft_addchartable(info->board, ft_memalloc(SZBOARDX, '\0'), (SZBOARDY + 1));
            break;
        }
    }
    dprintf(info->fds, "999999999999999999999999999999999999999999999999\n");
}

void get_piece(int fd, char *line, t_info *info)
{
    int ret;
    int i;

    ret = 0;
    i = 0;
    dprintf(info->fds, "+++++++++++++++++++++++++++++++++++++++\n");
    info->piece_sizey = ft_atoi(&line[6]);
    info->piece_sizex = ft_atoi(&line[8]);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if ((line[0] == '.') || (line[0] == '*'))
        {
            info->piece = ft_addchartable(info->piece, line, SZBOARDY);
            i++;
        }
        if (i == SZPIECEY)
            break;
    }
    dprintf(info->fds, "||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}

int     filler_read(int fdr, t_info *info)
{
    int     ret;
    char    *line;

    ret = 0;
    while ((ret = get_next_line(0, &line)) > 0)
    {
        dprintf(info->fds, "*%s*\n", line);
        if(IP == 0)
            get_player(line, info);
        if (ft_strstr(line, "Plateau"))
        {
            dprintf(info->fds, "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            get_board(0, line, info);
        }
        if (ft_strstr(line, "Piece"))
        {
            get_piece(0, line, info);
            break;
        }
    }
    return (0);
}
