/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/16 20:25:05 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int     ft_if_valide(int y, int x, t_info *info)
{
    int     ok;

    ok == 0;
    if (!Iboard[Iy + y][Ix + x])
        return (0);
    if (Iboard[Iy + y][Ix + x] == 'O')
        ok++;
    if (Iboard[Iy + y][Ix + x] == '.')
        
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
                i++;
            else if (Ipiece[y][x] == '*')
        }
        j++;
    }

}

int     ft_check_pos();

int    ft_play_filler(t_info *info)
{
    int     i;

    i = 0;
    info->y = 0;
    while (Iboard[Iy])
    {
        info->x = 0;
        while (Iboard[Ix])
        {
            ft_check_piece_pos(info);

            ft_check_pos();
        }
        Iy++;
    }
}