/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/10 15:25:23 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./filler.h"

int     main ()
{
    int     fdr = open("./patate", O_CREAT | O_RDWR | O_TRUNC, 0666);
    char    *line;
    int     i;
    t_info  *info;

    info = ft_memalloc(sizeof(t_list), '\0');
    info->player = 0;
    info->piece = NULL;
    line = NULL;
    while ((ft_filler_read(fdr, info)) > 0)
    {
        ft_printf("Started\n");
    }
    return (0);
}