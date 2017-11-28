/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/28 18:56:47 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int     ft_if_valide(int y, int x, t_info *info)
{
    int     ok;

    ok == 0;
    if (!Iboard[Iy + (y - My)][Ix + (x - Mx)] || 
        !Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'X')
        return (0);
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'O')
        ok++;
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == '.')
        return (ok);
}

int     ft_check_piece_pos(t_info *info)
{
    int     x;
    int     y;
    int     ok;

    y = 0;
    ok = 1;
    while (Ipiece[y] && ok == 1)
    {
        x = 0;
        while (Ipiece[x] && ok == 1)
        {
            if (Ipiece[y][x] == '.')
                x++;
            if (Mar == 0 && (Ipiece[y][x] == '*'))
            {
                Mar = 1;
                Mx = x;
                My = y;
            }
            if ((Ipiece[y][x] == '*'))
        }
        y++;
    }

}

int     ft_check_pos();

int    ft_play_filler(t_info *info)
{
    int     i;

    i = 0;
    info->y = 0;
    info->margin = 0;
    while (Iboard[Iy])
    {
        info->x = 0;
        while (Iboard[Iy][Ix])
        {
            ft_check_piece_pos(info);

            ft_check_pos();
            Ix++;
        }
        Iy++;
    }
}