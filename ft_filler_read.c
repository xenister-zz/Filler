/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2017/12/22 17:40:46 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void    get_player(char *line, t_info *info)
{
    if (ft_strstr(line, "p1"))
        info->player = 1;
    if (ft_strstr(line, "p2"))
        info->player = 2;
}

void    get_board(int fd, char *line, t_info *info)
{
    int size;
    int size2;
    int ret;
    int i;
    

    ret = 0;
    i = 0;
    size = ft_atoi(&line[8]);
    size2 = ft_atoi(&line[11]);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (line[0] == '0')
        {
            info->board = ft_addtable(info->board, &line[4], size);
            i++;
        }
        if (i == size)
        {
            info->board = ft_addtable(info->board, ft_memalloc(size2, '\0'), (size + 1));
            break;
        }
    }
}

void get_piece(int fd, char *line, t_info *info)
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

int     filler_read(int fdr, t_info *info)
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
