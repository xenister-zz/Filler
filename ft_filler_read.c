/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/11 21:01:58 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void    ft_get_player(char *line, t_info *info)
{
    //ft_printf("Strat Get Player\n");
    if (ft_strstr(line, "p1"))
        info->player = 1;
    //ft_printf("End get player 1\n");
    if (ft_strstr(line, "p2"))
        info->player = 2;
    //ft_printf("End get player 2\n");
}

void    ft_get_board(int fd, char *line, t_info *info)
{
    int size;
    int ret;
    int i;

    ret = 0;
    i = 0;
    size = ft_atoi(&line[8]);
    printf("size = %d\n", size);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (line[0] == '0' && (i++))
            ft_addtable(info->board, &line[4], size);
        if (i == size - 1)
            break;
    }
    ft_print_table(info->board, 0);
}

void ft_get_piece(int fd, char *line, t_info *info)
{
    int size;
    int ret;
    int i;

    ret = 0;
    i = 0;
    size = ft_atoi(&line[6]);
    printf("size = %d", size);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (((line[0] == '.') || (line[0] == '*')) && (i++))
            ft_addtable(info->board, line, size);
        if (i == size - 1)
            break;
    }
    ft_print_table(info->piece, 0);
}

int     ft_filler_read(int fdr, t_info *info)
{
    int     ret;
    char    *line;
    int     boo;

    boo = 0;
    int fd = open("./pate", O_CREAT | O_RDWR, 0666);
    ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if(info->player == 0)
        {
            printf("In Player Select\n");
            ft_get_player(line, info);
            printf("player = %d\n", info->player);
        }
        if (ft_strstr(line, "Plateau"))
            ft_get_board(fd, line, info);
        if (ft_strstr(line, "Piece"))
            ft_get_piece(fd, line, info);
    }
    ft_print_table(info->board, 0);
    ft_print_table(info->piece, 0);
    return (ret);
}