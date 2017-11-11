/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:04:04 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/11 19:19:31 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "./LibftXen/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct  s_info
{
    int     player;
    char    **piece;
    int     x;
    int     y;
    char    **board;
}               t_info;

void            ft_get_player(char *line, t_info *info);
int             ft_filler_read(int fdr, t_info *info);
void            ft_get_board(int fd, char *line, t_info *info);

#endif