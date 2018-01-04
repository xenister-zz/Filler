/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:04:04 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/04 15:41:52 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "./LibftXen/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define Iboard info->board
#define Is_board info->score_board
#define Ipiece info->piece
#define Ix info->x
#define Iy info->y
#define IOK info->ok
#define Mar info->margin
#define Mx info->marginx
#define My info->marginy

typedef struct  s_info
{
    int     size;
    int     size2;
    int     ok;
    int     okcount;
    int     player;
    char    **piece;
    int     x;
    int     y;
    int     score;
    int     **score_board;
    int     Sx;
    int     Sy;
    int     margin;
    int     marginx;
    int     marginy;
    char    **board;
    int     fds;
}               t_info;

void            get_player(char *line, t_info *info);
int             filler_read(int fdr, t_info *info);
void            get_board(int fd, char *line, t_info *info);
void            get_piece(int fd, char *line, t_info *info);
int             play_filler(int fdr, t_info *info);
int             if_valide(int y, int x, t_info *info);
int             check_piece_pos(t_info *info);

#endif