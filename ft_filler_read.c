/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/14 16:30:01 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void    ft_get_player(char *line, t_info *info)
{
    if (ft_strstr(line, "p1"))
        info->player = 1;
    if (ft_strstr(line, "p2"))
        info->player = 2;
}

void    ft_get_board(int fd, char *line, t_info *info)
{
    int size;
    int ret;
    int i;

    ret = 0;
    i = 0;
    size = ft_atoi(&line[8]);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (line[0] == '0')
        {
            info->board = ft_addtable(info->board, &line[4], size);
            i++;
        }
        if (i == size)
            break;
    }
}

void ft_get_piece(int fd, char *line, t_info *info)
{
    int size;
    int ret;
    int i;

    ret = 0;
    i = 0;
    size = ft_atoi(&line[6]);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if ((line[0] == '.') || (line[0] == '*'))
        {
            info->piece = ft_addtable(info->piece, line, size);
            i++;
        }
        if (i == size)
            break;
    }
}

int     ft_filler_read(int fdr, t_info *info)
{
    int     ret;
    char    *line;
    int     boo;

    boo = 0;
    //int fd = open("./pate", O_CREAT | O_RDWR, 0666);
    ret = 0;
    while ((ret = get_next_line(0, &line)) > 0)
    {
        //dprintf(fdr, "%i\n", ret);
        if(info->player == 0)
            ft_get_player(line, info);
        if (ft_strstr(line, "Plateau"))
            ft_get_board(0, line, info);
        if (ft_strstr(line, "Piece"))
        {
            ft_get_piece(0, line, info);
            break;
        }
    }
    boo = 0;
    while (info->board[boo])
    {
        dprintf(fdr, "%s\n", info->board[boo++]);
    }
    boo = 0;
    while (info->piece[boo])
    {
        dprintf(fdr, "%s\n", info->piece[boo++]);
    }
    return (0);
}
