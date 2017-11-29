/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:04:04 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/29 20:13:10 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "./LibftXen/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define Iboard info->board
#define Ipiece info->piece
#define Ix info->x
#define Iy info->y
#define IOK info->ok
#define Mar info->margin
#define Mx info->marginx
#define My info->marginy

typedef struct  s_info
{
    int     ok;
    int     okcount;
    int     player;
    char    **piece;
    int     x;
    int     y;
    int     score;
    int     margin;
    int     marginx;
    int     marginy;
    char    **board;
    int     fds;
}               t_info;

void            ft_get_player(char *line, t_info *info);
int             ft_filler_read(int fdr, t_info *info);
void            ft_get_board(int fd, char *line, t_info *info);
void            ft_get_piece(int fd, char *line, t_info *info);
int             ft_play_filler(int fdr,t_info *info);
int             ft_if_valide(int y, int x, t_info *info);
int             ft_check_piece_pos(t_info *info);

#endif