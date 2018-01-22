/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/22 19:56:26 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./LibftXen/ft_printf.h"

#include "./filler.h"

int     main ()
{
    char    *line;
    int     i;
    t_info  *info;

    info = ft_memalloc(sizeof(t_info), 0);
    info->fds = open("./patate", O_CREAT | O_RDWR | O_TRUNC, 0666);
    info->fdd = open("./poundai", O_CREAT | O_RDWR | O_TRUNC, 0666);
    line = NULL;
    IP = 0;
    F_SCORE = 0;
    SCORE= 0;
    //dprintf(info->fds, "STARTING WHILE\n");
    while (1)
    {
        dprintf(info->fds, "+++START\n");
        filler_read(info->fds, info);
        dprintf(info->fds, "+++END READ START PLAY\n");
        i = play_filler(info->fds, info);
        dprintf(info->fds, "+++END PLAY I == %d\n", i);
        //dprintf(info->fds, "+++SORTIE NO MARGIN =============== %d * %d\n", SY, SX);
        //dprintf(info->fds, "+++SORTIE =============== %d * %d | I== %d\n", (SY - MY), (SX - MX), i);
        if (i == 2 && F_SCORE == 0)
        {
            dprintf(info->fds, "----------BREAK---------");
            break;
        }
        if (F_SCORE != 0)
        {
            dprintf(info->fds, "++SORTIE NO MARGIN ********** %d * %d\n", SY, SX);
            //dprintf(info->fds, "++SORTIE ******************** %d * %d | I== %d\n", (SY - MY), (SX - MX), i);
            ft_printf("%d %d\n", (SY - MY), (SX - MX));
        }
        IBOARD = NULL;
        IPIECE = NULL;
    }
    return (0);
}