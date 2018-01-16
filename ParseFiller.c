/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/16 18:23:21 by susivagn         ###   ########.fr       */
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
    dprintf(info->fds, "STARTING WHILE\n");
    while (1)
    {
        dprintf(info->fds, "START\n");
        filler_read(info->fds, info);
        dprintf(info->fds, "READ OK\n");
        i = play_filler(info->fds, info);
        if ((i == 2) && (F_SCORE != 0))
            break;
        dprintf(info->fds, "SORTIE =============== %d %d\n", (IY - MY), (IX - MX));
        ft_printf("%d %d\n", (IY - MY), (IX - MX));
        IBOARD = NULL;
        IPIECE = NULL;
    }
    
    return (0);
}