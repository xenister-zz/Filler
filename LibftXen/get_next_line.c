/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:24:13 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/01 09:35:52 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delstructlst(t_list **lst, int fd)
{
	t_list *pre;
	t_list *actu;

	actu = (*lst);
	while (actu && (pre = actu) && ((t_lol *)(actu)->content)->fdi != fd)
		actu = (actu)->next;
	if (actu)
	{
		free(actu->content);
		if (actu->next != NULL && pre != actu)
		{
			pre->next = actu->next;
			actu->next = NULL;
		}
		else if (pre == actu)
		{
			(*lst) = NULL;
			actu->next = NULL;
		}
		else
			pre->next = NULL;
		free(actu);
	}
}

int		ft_organise(t_lol *buffer, char **line)
{
	char	*tmp;
	int		c;
	int		d;

	c = 0;
	d = 0;
	if (((c = ft_strclen(BB, '\n')) && (ft_strchr(BB, '\n'))) || BB[0] == '\n')
	{
		tmp = ft_strsub(BB, 0, c);
		*line = ft_append(*line, tmp, 1);
		free(tmp);
		ft_memmove(BB, &BB[c + 1], ft_strlen(BB) - c);
		d = 1;
	}
	else
	{
		*line = ft_append(*line, BB, 1);
		BB[0] = '\0';
	}
	return (d);
}

int		ft_getline(t_lol *buffer, char **line, int fd)
{
	int	n;
	int	d;

	n = 1;
	*line = ft_strnew(0, '\0');
	buffer->fdi = fd;
	d = ft_organise(buffer, line);
	while (d == 0 && (n = read(fd, BB, BUFF_SIZE)))
	{
		if (n <= 0)
			return (n);
		BB[n] = '\0';
		if (ft_strchr(BB, '\n'))
			d = ft_organise(buffer, line);
		else
		{
			*line = ft_append(*line, BB, 1);
			BB[0] = '\0';
		}
		if (n == -1)
			break ;
	}
	n = (n == 0 && d == 0) ? ft_strlen(*line) : n;
	return (n);
}

int		gnl_del(int fd, char **line, t_list *base)
{
	if (fd == -2 && !line)
		ft_lstdel(&base, &ft_del);
	if (fd < 0 || !line)
		return (-1);
	else
		return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*base;
	t_list			*navi;
	t_lol			*rest;
	int				n;

	rest = 0;
	if (gnl_del(fd, line, base) < 0)
		return (-1);
	navi = base;
	while (navi && NCF != fd)
		navi = NX;
	if (!navi)
	{
		rest = ft_memalloc(sizeof(*rest), '\0');
		rest->buff[0] = '\0';
		ft_lstadd(&base, (navi = ft_lstnew(rest, sizeof(*rest))));
		free(rest);
	}
	n = ft_getline((t_lol *)navi->content, line, fd);
	if (n == -1 || n == 0)
	{
		ft_delstructlst(&base, fd);
		return (n);
	}
	return (n = (n > 0) ? 1 : n);
}
