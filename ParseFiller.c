/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/17 17:23:32 by susivagn         ###   ########.fr       */
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
    line = NULL;
    F_SCORE = 0;
    SCORE= 0;
    dprintf(info->fds, "STARTING WHILE\n");
    while (1)
    {
        dprintf(info->fds, "START\n");
        filler_read(info->fds, info);
        dprintf(info->fds, "START2\n");
        i = play_filler(info->fds, info);
        if (i == 2 && F_SCORE == 0)
        {
            dprintf(info->fds, "----------BREAK---------");
            break;
        }
        if (F_SCORE != 0)
        {
            dprintf(info->fds, "SORTIE =============== %d * %d | I== %d\n", (SY - MY), (SX - MX), i);
            ft_printf("%d %d\n", (SY - MY), (SX - MX));
        }
        IBOARD = NULL;
        IPIECE = NULL;
    }
    return (0);
}