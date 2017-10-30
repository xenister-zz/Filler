/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2017/10/26 17:53:41 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "LibftXen/ft_printf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int     main ()
{

    int     fd = open("./patate", O_CREAT | O_RDWR | O_TRUNC, 0666);
    char    *line;
    int     i;
    line = NULL;
    while ((i = (get_next_line(0, &line))) > 0)
    {
        dprintf(fd, "%s\n", line);
        dprintf(1, "8 2\n");
    }
    return(0);
}