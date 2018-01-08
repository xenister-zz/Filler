/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:04:04 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/08 18:05:06 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "./LibftXen/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define IBOARD info->board
#define SZBOARDY info->board_sizey
#define SZBOARDX info->board_sizex
#define SZPIECEY info->piece_sizey
#define SZPIECEX info->piece_sizex
#define SCORE info->score
#define F_SCORE info->finalscore
#define IPIECE info->piece
#define IX info->x
#define IY info->y
#define IOK info->ok
#define MAR info->margin
#define MX info->marginx
#define MY info->marginy

typedef struct  s_info
{
    int     frein;
    char    **board;
    int     board_sizey;
    int     board_sizex;
    int     ok;
    int     okcount;
    int     player;
    char    **piece;
    int     piece_sizey;
    int     piece_sizex;
    int     x;
    int     y;
    int     score;
    int     finalscore;
    int     Sx;
    int     Sy;
    int     margin;
    int     marginx;
    int     marginy;
    int     fds;
}               t_info;

void            get_player(char *line, t_info *info);
int             filler_read(int fdr, t_info *info);
void            get_board(int fd, char *line, t_info *info);
void            get_piece(int fd, char *line, t_info *info);
int             play_filler(int fdr, t_info *info);
int             if_valide(int y, int x, t_info *info);
int             check_piece_pos(t_info *info);
int             chauffage(t_info *info);

#endif