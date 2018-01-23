/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:31:06 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/23 15:12:33 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

int     if_valide(int y, int x, t_info *info)
{
    y = y - MY;
    x = x - MX;
    if (!(IBOARD[IY + y]) || !(IBOARD[IY + y][IX + x]))
            return (0);
    if (IBOARD[IY + y][IX + x] == IE)
            return (0);
    if (IBOARD[IY + y][IX + x] == IP)
        {
            info->okcount++;
            SCORE += 46;
            return(1);
        }
    if (IBOARD[IY + y][IX + x] == '.' || IBOARD[IY + y][IX + x] == '@' || 
            IBOARD[IY + y][IX + x] == '<' || IBOARD[IY + y][IX + x] == '[')
        {  
            SCORE += IBOARD[IY + y][IX + x];
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
                dprintf(info->fds, "MARGIN ===== %d * %d \n", MY, MX);
            }
            if ((IPIECE[y][x] == '*') && (nbpiece--) && ((if_valide(y, x, info) != 1)))
                return (0);
            x++;
        }
        y++;
    }
    if (info->okcount != 1)
    {
        return (0);
    }
    return(1);
}

int        chauffage_border(t_info *info)
{
    int     y;
    int     x;
    int     boo;
    char       c;

    y = 0;
    boo = 0;
    if (info->plateau == 1)
        c = '[';
    else
        c = '<';
    while ((IBOARD) && IBOARD[y])
    {
        x = 0;
        while ((IBOARD) && IBOARD[y] && IBOARD[y][x])
        {
            if ((y == 1 || y == (SZBOARDY - 2)) && (IBOARD[y][x] == '.'))
                IBOARD[y][x] = c;
            else if ((x == 1 || x == (SZBOARDX - 2)) && (IBOARD[y][x] == '.'))
                IBOARD[y][x] = c;
            x++;
        }
        y++;
    }
    return (0);

}

int        chauffage_enemy(t_info *info)
{
    int     y;
    int     x;
    int     boo;

    y = 0;
    //dprintf(info->fds, "*ENTREE--CHAUFFAGE---ENEMI-------*\n");
    while ((IBOARD) && IBOARD[y])
    {
        x = 0;
        while ((IBOARD) && IBOARD[y] && IBOARD[y][x])
        {
            //dprintf(info->fds, "*Y === %d --- X === %d ----*\n", y, x);
            if (IBOARD[y][x] == IE)
            {
                if ((x > 0) && (IBOARD[y][x - 1]) && (IBOARD[y][x - 1] == '.'))
                    IBOARD[y][x - 1] = '@';
                else if ((x < SZBOARDX) && (IBOARD[y][x + 1]) && (IBOARD[y][x + 1] == '.'))
                    IBOARD[y][x + 1] = '@';
                else if ((y > 0) && (IBOARD[y - 1][x]) && (IBOARD[y - 1][x] == '.'))
                    IBOARD[y - 1][x] = '@';
                else if ((y < SZBOARDY) && (IBOARD[y + 1][x]) && (IBOARD[y + 1][x] == '.'))
                    IBOARD[y + 1][x] = '@';
            }
            x++;
        }
        y++;
    }
    //dprintf(info->fds, "*EXIT--CHAUFFAGE---ENEMI-------*\n");
    return (0);

}

void    ft_set_score(t_info *info)
{
    F_SCORE = SCORE;
    SCORE = 0;
    SY = IY;
    SX = IX;
}

int    play_filler(int fdr, t_info *info)
{
    int     i;

    i = 0;
    IY = 0;
    info->margin = 0;
    SCORE = 0;
    F_SCORE = 0;
    SY = 0;
    SX = 0;
    //dprintf(fdr, "*START---CHAUFFAGE--ENNEMIE------------*\n");
    chauffage_enemy(info);
    //dprintf(fdr, "*END---CHAUFFAGE--ENNEMIE-+++++++++++++*\n");
    chauffage_border(info);
    //dprintf(fdr, "*PLAY FILLER START*\n");
    while ((IBOARD) && IBOARD[IY])
    {
        IX = 0;
        while ((IBOARD) && IBOARD[IY][IX])
        {
            if (check_piece_pos(info) == 1)
            {
                if ((SCORE >= F_SCORE) && (info->okcount == 1))
                    ft_set_score(info);
            }
            //dprintf(info->fds, "BOARD Y == %d | X == %d \n", IY, IX);
            if ((F_SCORE == 0) && ((IY == SZBOARDY - 1) && (IX == SZBOARDX - 1)))
            {
                //dprintf(info->fds, "EXIT ON IF ON PLAY FILLER -%d-----\n", F_SCORE);
                return(2);
            }
            IX++;
        }
        IY++;
    }
    //dprintf(info->fds, "NORMAL EXIT ON PLAY FILLER -%d----- \n", F_SCORE);
    return(1);
}