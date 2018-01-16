/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/16 19:31:52 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

// int     if_validep1(int y, int x, t_info *info)
// {
//     dprintf(info->fds, "CHECK VALID\n");
//     if (!(IBOARD[IY + (y - MY)][IX + (x - MX)]))
//         {
//             dprintf(info->fds, "            ITS NULL\n");
//             return (0);
//         }
//     if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'X')
//         {
//             dprintf(info->fds, "            ITS *X*\n");
//             return (0);
//         }
//     if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'O')
//         {
//             dprintf(info->fds, "            ITS *O*\n");
//             info->okcount++;
//             return(1);
//         }
//     if (IBOARD[IY + (y - MY)][IX + (x - MX)] == '.')
//         {
//             dprintf(info->fds, "            VALID ZONE\n");
//             return (1);
//         }
//     return (0);
// }

// int     if_validep2(int y, int x, t_info *info)
// {
//     dprintf(info->fds, "CHECK VALID\n");
//     if (!(IBOARD[IY + (y - MY)][IX + (x - MX)]))
//         {
//             dprintf(info->fds, "            ITS NULL\n");
//             return (0);
//         }
//     if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'O')
//         {
//             dprintf(info->fds, "            ITS *X*\n");
//             return (0);
//         }
//     if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'X')
//         {
//             dprintf(info->fds, "            ITS *O*\n");
//             info->okcount++;
//             return(1);
//         }
//     if (IBOARD[IY + (y - MY)][IX + (x - MX)] == '.')
//         {
//             dprintf(info->fds, "            VALID ZONE\n");
//             return (1);
//         }
//     return (0);
// }

int     if_validep1(int y, int x, t_info *info)
{
    dprintf(info->fds, "CHECK VALID ON %d - %d\n", IY, IX);
    if (!(IBOARD[IY + (y - MY)][IX + (x - MX)]))
        {
            dprintf(info->fds, "            ITS NULL\n");
            return (0);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'X')
        {
            dprintf(info->fds, "            ITS *X*\n");
            return (0);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'O')
        {
            dprintf(info->fds, "            ITS *O*\n");
            info->okcount++;
            SCORE += 46;
            return(1);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == '.')
        {  
            SCORE += IBOARD[IY + (y - MY)][IX + (x - MX)];
            dprintf(info->fds, "            VALID SCORE = %d\n", SCORE);
            return (1);
        }
    return (0);
}

int     if_validep2(int y, int x, t_info *info)
{
    dprintf(info->fds, "CHECK VALID ON %d - %d\n", IY, IX);
    if (!(IBOARD[IY + (y - MY)][IX + (x - MX)]))
        {
            dprintf(info->fds, "            ITS NULL\n");
            return (0);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'O')
        {
            dprintf(info->fds, "            ITS *X*\n");
            return (0);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == 'X')
        {
            dprintf(info->fds, "            ITS *X*\n");
            SCORE += 46;
            info->okcount++;
            return(1);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == '.')
        {
            SCORE += IBOARD[IY + (y - MY)][IX + (x - MX)];
            dprintf(info->fds, "            VALID SCORE = %d\n", SCORE);
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
    SCORE = 0;
    while (IPIECE[y])
    {
        nbpiece += ft_count_char(IPIECE[y], '*');
        y++;
    }
    y = 0;
    while (IPIECE[y] && (nbpiece > 0))
    {
        x = 0;
        while (IPIECE[y][x] && (nbpiece > 0))
        {
            if (MAR == 0 && (IPIECE[y][x] == '*'))
            {
                MAR = 1;
                MX = x;
                MY = y;
            }
            if (info->player == 1)
            {
                if ((IPIECE[y][x] == '*') && (nbpiece--) && ((if_validep1(y, x, info) != 1)))
                    return (0);
            }
            else
            {
                if ((IPIECE[y][x] == '*') && (nbpiece--) && ((if_validep2(y, x, info) != 1)))
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

int     last_in_tab(t_info *info)
{
    int     i;

    i = 0;
    return (0);
}

int     chauffage(t_info *info)
{
    int     i;

    i = -1;
    while (IBOARD[++i] && (IBOARD[i][0] == '.') && (IBOARD[i][0] != 'X') && (IBOARD[i][0] != 'O'))
        IBOARD[i][0] = '<';
    i = -1;
    while (IBOARD[0][++i] && (IBOARD[0][i] == '.') && (IBOARD[0][i] != 'X') && (IBOARD[0][i] != 'O'))
        IBOARD[0][i] = '<';
    i = -1;
    while (IBOARD[++i][SZBOARDX - 1] && (IBOARD[i][SZBOARDX - 1] == '.') && (IBOARD[i][SZBOARDX - 1] != 'X') && (IBOARD[i][SZBOARDX - 1] != 'O'))
        IBOARD[i][SZBOARDX] = '<';
    i = -1;
    while (IBOARD[SZBOARDY - 1][++i] && (IBOARD[SZBOARDY - 1][i] == '.') && (IBOARD[SZBOARDY - 1][i] != 'X') && (IBOARD[SZBOARDY - 1][i] != 'O'))
        IBOARD[SZBOARDY - 1][i] = '<';
    return (0);
}

void    ft_set_score(t_info *info)
{
    F_SCORE = SCORE;
    SCORE = 0;
    info->Sy = IY;
    info->Sx = IX;
}

int    play_filler(int fdr, t_info *info)
{
    int     i;

    i = 0;
    info->y = 0;
    info->margin = 0;
    SCORE = 0;
    F_SCORE = 0;
    dprintf(fdr, "*PLAY FILLER START*\n");
    while (IBOARD[IY])
    {
        info->x = 0;
        while (IBOARD[IY][IX])
        {
            if (check_piece_pos(info) == 1)
            {
                if (SCORE > F_SCORE)
                    ft_set_score(info);
                if ((IY == SZBOARDY - 1) && (IX == SZBOARDX - 1) && SCORE == 0)
                    return(2);
            }
            //ft_check_pos();
            IX++;
        }
        IY++;
    }
    return(1);
}
