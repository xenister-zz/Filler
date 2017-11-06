/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseFiller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:21:39 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/06 17:44:00 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "LibftXen/libft.h"
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
       // dprintf(1, "69 70\n");
    }
    return (0);
}