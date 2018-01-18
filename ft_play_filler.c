/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/18 19:41:32 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int     if_valide(int y, int x, t_info *info)
{
    //dprintf(info->fds, "CHECK VALID ON %d - %d\n", IY, IX);
    if (!(IBOARD[IY + (y - MY)][IX + (x - MX)]))
        {
            //dprintf(info->fds, "            ITS NULL\n");
            return (0);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == IE)
        {
            //dprintf(info->fds, "            ITS *X*\n");
            return (0);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] == IP)
        {
            //dprintf(info->fds, "            ITS *O*\n");
            info->okcount++;
            SCORE += 46;
            return(1);
        }
    if (IBOARD[IY + (y - MY)][IX + (x - MX)] != IE)
        {  
            SCORE += IBOARD[IY + (y - MY)][IX + (x - MX)];
            //dprintf(info->fds, "            VALID SCORE = %d\n", SCORE);
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
            if ((IPIECE[y][x] == '*') && (nbpiece--) && ((if_valide(y, x, info) != 1)))
                return (0);
            x++;
        }
        y++;
    }
    if (info->okcount != 1)
        return (0);
    //dprintf(info->fds, " SORTIE ----------------------------DE CHECK PIECE*\n");
    return(1);
}

int        chauffage_border(t_info *info)
{
    int     y;
    int     x;
    int     boo;

    y = 0;
    boo = 0;
    while (IBOARD[y])
    {
        x = 0;
        while (IBOARD[y][x])
        {
            if ((y == 1 || y == (SZBOARDY - 2)) && (IBOARD[y][x] == '.'))
                IBOARD[y][x] = '<';
            else if ((x == 1 || x == (SZBOARDX - 2)) && (IBOARD[y][x] == '.'))
                IBOARD[y][x] = '<';
            x++;
        }
        y++;
    }
    while (info->board[boo])
    {
        dprintf(info->fds, "%s\n", info->board[boo++]);
    }
    boo = 0;
    while (info->piece[boo])
    {
        dprintf(info->fds, "%s\n", info->piece[boo++]);
    }
    return (0);

}

int        chauffage_enemy(t_info *info)
{
    int     y;
    int     x;
    int     boo;

    y = 0;
    while (IBOARD[y])
    {
        x = 0;
        while (IBOARD[y][x])
        {
            if (IBOARD[y][x] == IE)
            {
                if ((IBOARD[y][x - 1]) && IBOARD[y][x - 1] == '.')
                    IBOARD[y][x - 1] = '@';
                if ((IBOARD[y][x + 1]) && IBOARD[y][x + 1] == '.')
                    IBOARD[y][x + 1] = '@';
                if ((IBOARD[y - 1][x]) && IBOARD[y - 1][x] == '.')
                    IBOARD[y - 1][x] = '@';
                if ((IBOARD[y + 1][x]) && IBOARD[y + 1][x] == '.')
                    IBOARD[y + 1][x] = '@';
            }
            x++;
        }
        y++;
    }
    return (0);

}

void    ft_set_score(t_info *info)
{
    //dprintf(info->fds, "*----IY == %d | *----IX == %d \n", IY, IX);
    F_SCORE = SCORE;
    SCORE = 0;
    SY = IY;
    SX = IX;
    //dprintf(info->fds, "*----FSCORE == %d*\n", F_SCORE);
}

int    play_filler(int fdr, t_info *info)
{
    int     i;

    i = 0;
    info->y = 0;
    info->margin = 0;
    SCORE = 0;
    F_SCORE = 0;
    chauffage_enemy(info);
    chauffage_border(info);
    dprintf(fdr, "*PLAY FILLER START*\n");
    while (IBOARD[IY])
    {
        IX = 0;
        while (IBOARD[IY][IX])
        {
            if (check_piece_pos(info) == 1)
            {
                if ((SCORE >= F_SCORE) && (info->okcount == 1))
                    ft_set_score(info);
            }
            if ((F_SCORE == 0) && ((IY == SZBOARDY - 1) && (IX == SZBOARDX - 1)))
            {
                dprintf(fdr, " --------------------------------WAKAWAWE*\n");
                return(2);
            }
            //ft_check_pos();
            IX++;
        }
        IY++;
    }
    dprintf(info->fds, " -------------ILSORTNORMAL*\n");
    dprintf(info->fds, " ---------FSCORE ====== %d*\n", F_SCORE);
    return(1);
}
