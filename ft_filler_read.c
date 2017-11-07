/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/07 18:43:31 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

void    ft_get_player(char *line, t_info *info)
{
    if (ft_strstr(line, "p1\0"))
        info->player = 1;
    if (ft_strstr(line, "p2\0"))
        info->player = 2;
}

void    ft_get_piece(char *line, t_info *info)
{
    char    *find;

    find = ft_strstr(line, "Piece");
    ft_printf("find1 == %s", find);
    find = ft_strstr(line, ":");
    find = find + 2;
    info->piece = ft_strsplit(find, '\n');
}

int     ft_filler_read(int fdr, t_info *info)
{
    int     ret;
    char    *line;

    int fd = open("./pate", O_CREAT | O_RDWR, 0666);
    ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if(info->player == 0)
        {
            ft_get_player(line, info);
            //dprintf(fdr, "player = %d", info->player);
        }
        if (info->piece == NULL)
            ft_get_piece(line, info);
    }

    return (ret);
}