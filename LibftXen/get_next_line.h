/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:46:46 by susivagn          #+#    #+#             */
/*   Updated: 2017/10/21 18:08:51 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1													
# define NX navi->next
# define NCF ((t_lol *)(navi)->content)->fdi
# define BB buffer->buff

# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

typedef struct	s_lol
{
	int			fdi;
	char		buff[BUFF_SIZE + 1];
}				t_lol;

int				get_next_line(const int fd, char **line);

#endif
