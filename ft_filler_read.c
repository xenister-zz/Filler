/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/05 16:29:59 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void    get_player(char *line, t_info *info)
{
    if (ft_strstr(line, "p1"))
        info->player = 1;
    else
        info->player = 2;
    dprintf(info->fds, "players ================== %d\n", info->player);
}

void    get_board(int fd, char *line, t_info *info)
{
    int ret;
    int i;
    

    ret = 0;
    i = 0;
    info->size = ft_atoi(&line[8]);
    info->size2 = ft_atoi(&line[11]);
    dprintf(info->fds, "board size1 = %d - board size2 = %d\n", info->size , info->size2);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (line[0] == '0')
        {
            info->board = ft_addchartable(info->board, &line[4], info->size + 1);
            i++;
        }
        if (i == info->size)
        {
            dprintf(info->fds, "THERE i = %d \n", i);
            info->board = ft_addchartable(info->board, ft_memalloc(info->size2, '\0'), (info->size + 1));
            break;
        }
    }
}

void get_piece(int fd, char *line, t_info *info)
{
    int ret;
    int i;

    ret = 0;
    i = 0;
    info->size = ft_atoi(&line[6]);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if ((line[0] == '.') || (line[0] == '*'))
        {
            info->piece = ft_addchartable(info->piece, line, info->size);
            i++;
        }
        if (i == info->size)
            break;
    }

}

int     filler_read(int fdr, t_info *info)
{
    int     ret;
    char    *line;
    int     boo;

    boo = 0;
    info->fds = fdr;
    ret = 0;
    while ((ret = get_next_line(0, &line)) > 0)
    {
        //dprintf(fdr, "%i\n", ret);
        if(info->player == 0)
            get_player(line, info);
        if (ft_strstr(line, "Plateau"))
            get_board(0, line, info);
        if (ft_strstr(line, "Piece"))
        {
            get_piece(0, line, info);
            break;
        }
    }
    boo = 0;
    // while (info->board[boo])
    // {
    //     dprintf(fdr, "%s\n", info->board[boo++]);
    // }
    // boo = 0;
    // while (info->piece[boo])
    // {
    //     dprintf(fdr, "%s\n", info->piece[boo++]);
    // }
    return (0);
}
