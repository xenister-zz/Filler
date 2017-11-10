/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:25 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/10 17:27:04 by susivagn         ###   ########.fr       */
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

void    ft_get_piece(char *line, t_info *info)
{
    char    *find;

    
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
            ft_printf("In Player Select\n");
            ft_get_player(line, info);
            ft_printf("player = %d\n", info->player);
        }
        if (info->piece == NULL)
            ft_get_piece(line, info);
    }
    return (ret);
}