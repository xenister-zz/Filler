/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/04 19:05:16 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int     if_valide(int y, int x, t_info *info)
{
    dprintf(info->fds, "CHECK VALID\n");
    if (!(Iboard[Iy + (y - My)][Ix + (x - Mx)]))
        {
            dprintf(info->fds, "            ITS NULL\n");
            return (0);
        }
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'X')
        {
            dprintf(info->fds, "            ITS *X*\n");
            return (0);
        }
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'O')
        {
            dprintf(info->fds, "            ITS *O*\n");
            info->okcount++;
            return(1);
        }
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == '.')
        {
            dprintf(info->fds, "            VALID ZONE\n");
            return (1);
        }
    return (0);
}

int     check_piece_pos(t_info *info)
{
    int     x;
    int     y;
    int     nbpiece;

    y = 0;
    nbpiece = 0;
    info->ok = 1;
    info->okcount = 0;
    dprintf(info->fds, "start NTM %d - %d\n", Iy, Ix);

    while (Ipiece[y])
    {
        nbpiece += ft_count_char(Ipiece[y], '*');
        y++;
    }
    //dprintf(info->fds, "nbr piece ========= %d\n", nbpiece);
    y = 0;
    while (Ipiece[y] && (nbpiece > 0))
    {
        x = 0;
        while (Ipiece[y][x] && (nbpiece > 0))
        {
            if (Mar == 0 && (Ipiece[y][x] == '*'))
            {
                Mar = 1;
                Mx = x;
                My = y;
                dprintf(info->fds, "MX = %d, MY = %d\n", Mx, My);
            }
            if ((Ipiece[y][x] == '*') && (nbpiece--) && ((if_valide(y, x, info) != 1)))
            {
                dprintf(info->fds, "EXIT NTM\n");
                return (0);
            }
            dprintf(info->fds, "PIECE ====%d\n", nbpiece);
            x++;
        }
        y++;
    }
    if (info->okcount != 1) 
    {
        dprintf(info->fds, "    BAD COUNT\n");
        return (0);
    }
    dprintf(info->fds, "    GOOD COUNT\n");
    dprintf(info->fds, "y == %d x == %d\n", Iy, Ix);
    return(1);
}

int     check_pos();
/*
int     chauffage(t_info *info);
{
    int     i;

    i = 0;
    
    
}
*/

int    play_filler(int fdr, t_info *info)
{
    int     i;

    i = 0;
    info->y = 0;
    info->margin = 0;
    dprintf(fdr, "start while\n");
    while (Iboard[Iy])
    {
        info->x = 0;
        while (Iboard[Iy][Ix])
        {
            if (check_piece_pos(info) == 1)
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
