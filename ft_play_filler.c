/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/05 20:06:00 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int     if_validep1(int y, int x, t_info *info)
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

int     if_validep2(int y, int x, t_info *info)
{
    dprintf(info->fds, "CHECK VALID\n");
    if (!(Iboard[Iy + (y - My)][Ix + (x - Mx)]))
        {
            dprintf(info->fds, "            ITS NULL\n");
            return (0);
        }
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'O')
        {
            dprintf(info->fds, "            ITS *X*\n");
            return (0);
        }
    if (Iboard[Iy + (y - My)][Ix + (x - Mx)] == 'X')
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

    while (Ipiece[y])
    {
        nbpiece += ft_count_char(Ipiece[y], '*');
        y++;
    }
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
            }
            if (info->player == 1)
            {
                if ((Ipiece[y][x] == '*') && (nbpiece--) && ((if_validep1(y, x, info) != 1)))
                    return (0);
            }
            else
            {
                if ((Ipiece[y][x] == '*') && (nbpiece--) && ((if_validep2(y, x, info) != 1)))
                    return (0);
            }
            x++;
        }
        y++;
    }
    if (info->okcount != 1)
        return (0);
    return(1);
}

int     check_pos();

int     chauffage(t_info *info);
{
    int     i;

    i = -1;
    while (Iboard[++i] && (Iboard[i][0] == '.') && (Iboard[i][0] != 'X') && (Iboard[i][0] != 'O'))
        Iboard[i][0] = '<';
    i = -1;
    while (Iboard[0][++i] && (Iboard[0][i] == '.') && (Iboard[0][i] != 'X') && (Iboard[0][i] != 'O'))
        Iboard[0][i] = '<';
    i = -1;
    while (Iboard[++i][IS2 - 1] && (Iboard[i][IS2 - 1] == '.') && (Iboard[i][IS2 - 1] != 'X') && (Iboard[i][IS2 - 1] != 'O'))
        Iboard[i][IS2] = '<';
    i = -1;
    while (Iboard[IS1 - 1][++i] && (Iboard[IS1 - 1][i] == '.') && (Iboard[IS1 - 1][i] != 'X') && (Iboard[IS1 - 1][i] != 'O'))
        Iboard[IS1 - 1][i] = '<';
    
    



    
    
}


int    play_filler(int fdr, t_info *info)
{
    int     i;

    i = 0;
    info->y = 0;
    info->margin = 0;
    dprintf(fdr, "*START PLAY FILLER*\n");
    while (Iboard[Iy])
    {
        info->x = 0;
        while (Iboard[Iy][Ix])
        {
            if (check_piece_pos(info) == 1)
            {
                //dprintf(fdr, "il est entré\n");
                return (1);
            }
            //ft_check_pos();
            Ix++;
        }
        Iy++;
    }
    if (!(Iboard[Iy]) || !(Iboard[Iy][Ix]))
        info->frein = 1;
    return(1);
}
