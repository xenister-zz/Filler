/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/08 19:10:44 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./LibftXen/ft_printf.h"

#include "./filler.h"

int     main ()
{
    int     fdr = open("./patate", O_CREAT | O_RDWR | O_TRUNC, 0666);
    char    *line;
    int     i;
    t_info  *info;

    info = ft_memalloc(sizeof(t_info), 0);
    line = NULL;
    while (1)
    {
        filler_read(fdr, info);
        dprintf(info->fds, "SORTIE ===============segfault haha\n");
        i = play_filler(fdr, info);
        if ((i == 2) && (F_SCORE != 0))
            break;
        dprintf(info->fds, "SORTIE =============== %d %d\n", (IY - MY), (IX - MX));
        ft_printf("%d %d\n", (IY - MY), (IX - MX));
        IBOARD = NULL;
        IPIECE = NULL;
    }
    
    return (0);
}