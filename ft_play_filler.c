/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/29 20:14:15 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int     ft_if_valide(int y, int x, t_info *info)
{
    if (!Iboard[Iy + (y - My)][Ix + (x - Mx)] || 
        Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'X')
        return (0);
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'O')
        info->okcount++;
    if (info->okcount > 1 || info->okcount < 1)
        return (0);
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == '.')
        return (1);
    return (0);
}

int     ft_check_piece_pos(t_info *info)
{
    int     x;
    int     y;

    y = 0;
    info->ok = 1;
    info->okcount = 0;
    dprintf(info->fds, "strat NTM\n");
    while (Ipiece[y])
    {
        x = 0;
        while (Ipiece[x])
        {
            if (Mar == 0 && (Ipiece[y][x] == '*'))
            {
                Mar = 1;
                Mx = x;
                My = y;
            }
            if ((Ipiece[y][x] == '*') && (ft_if_valide(y, x, info) != 1))
                return (0);
            x++;
        }
        y++;
    }
    return(1);
}

int     ft_check_pos();

int     chauffage();

int    ft_play_filler(int fdr, t_info *info)
{
    int     i;

    i = 0;
    info->y = 0;
    info->margin = 0;
    info->fds = fdr;
    dprintf(fdr, "strat while\n");
    while (Iboard[Iy])
    {
        info->x = 0;
        while (Iboard[Iy][Ix])
        {
            if (ft_check_piece_pos(info) == 1)
            {
                dprintf(fdr, "il est entré\n");
                return (1);
            }
            //ft_check_pos();
            Ix++;
        }
        Iy++;
    }
    return(1);
}