/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:04:04 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/01 03:28:16 by susivagn         ###   ########.fr       */
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
#define SY info->sy
#define SX info->sx
#define IPIECE info->piece
#define IX info->x
#define IY info->y
#define IOK info->ok
#define MAR info->margin
#define MX info->marginx
#define MY info->marginy
#define IP info->player
#define IE info->enemy

typedef struct  s_info
{
    char    **board;
    int     plateau;
    int     board_sizey;
    int     board_sizex;
    int     ok;
    int     okcount;
    char    player;
    char    enemy; 
    char    **piece;
    int     piece_sizey;
    int     piece_sizex;
    int     x;
    int     y;
    int     score;
    int     finalscore;
    int     sx;
    int     sy;
    int     margin;
    int     marginx;
    int     marginy;
    int     fds;
    int		fdd;
}				t_info;

void			get_player(char *line, t_info *info);
int				filler_read(int fdr, t_info *info);
void			get_board(int fd, char *line, t_info *info);
void			get_piece(int fd, char *line, t_info *info);
int				play_filler(int fdr, t_info *info);
int				if_valide(int y, int x, t_info *info);
int		        check_piece_pos(int	x, int y, t_info *info);
int             chauffage_enemy(int x, int y, t_info *info);
int				chauffage_border(t_info *info);
void			ft_set_score(t_info *info);
void			init_struct(t_info *info);
void	        free_tab(t_info *info, char **tab, int size);
void	        free_board(t_info *info, char **tab, int size);
int		        chauffage_map00(t_info *info, int x);

#endif