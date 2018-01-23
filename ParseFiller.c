/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/23 15:41:36 by susivagn         ###   ########.fr       */
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
    while (1)
    {
        filler_read(info->fds, info);
        i = play_filler(info->fds, info);
        if (i == 2 && F_SCORE == 0)
        {
            break;
        }
        if (F_SCORE != 0)
        {
            ft_printf("%d %d\n", (SY - MY), (SX - MX));
        }
        IBOARD = NULL;
        IPIECE = NULL;
    }
    return (0);
}

//seed filler: 
//- 2867
//carli me fk map01 en p2
//superjeannot sur map00 p1