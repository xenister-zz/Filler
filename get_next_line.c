/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:24:13 by susivagn          #+#    #+#             */
/*   Updated: 2017/10/30 17:59:31 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_cpy(char **line, char *buffer)
{
	char *temp;

	if (!(*line))
	{
		*line = ft_memalloc(sizeof(char) * ft_strlen(buffer), '\0');
		ft_strcpy(*line, buffer);
	}
	temp = *line;
	*line = ft_memalloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(temp)), '\0');
	ft_strcpy(*line, temp);
	ft_strcat(*line, buffer);
	ft_memdel((void *)&temp);
}

int ft_check_lf(char **line, char *buffer, char **memory)
{
	char *lf;
	char *temp;
	char *temp2;

	if (!(lf = ft_strchr(buffer, '\n')))
		return (0);
	*lf = '\0';
	lf += 1;
	temp = *line;
	*line = ft_memalloc(ft_strlen(buffer) + ft_strlen(temp), '\0');
	ft_strcpy(*line, temp);
	ft_strcat(*line, buffer);
	ft_memdel((void *)&temp);
	temp2 = *memory;
	*memory = ft_strdup(lf, 0);
	ft_memdel((void *)&temp2);
	return (1);
}

int ft_up(char **line, char **memory)
{
	char *lf;
	char *temp;
	char *temp2;

	if (!(lf = ft_strchr(*memory, '\n')))
	{
		temp = *line;
		*line = ft_strdup(*memory, 0);
		ft_memdel((void **)memory);
		ft_memdel((void *)&temp);
	}
	else
	{
		*lf = '\0';
		lf += 1;
		temp = *line;
		*line = ft_strdup(*memory, 0);
		temp2 = *memory;
		*memory = ft_strdup(lf, 0);
		ft_memdel((void *)&temp);
		ft_memdel((void *)&temp2);
		return (1);
	}
	return (0);
}

int get_next_line(int const fd, char **line)
{
	int 			ret;
	char 			buffer[BUFF_SIZE + 1];
	static char		*memory;

	if (fd == -1 || BUFF_SIZE <= 0 || !line ||
		!(*line = ft_memalloc((sizeof(char) * BUFF_SIZE), '\0')))
		return (-1);
	if (memory && ft_up(line, &memory))
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		if (ft_check_lf(line, buffer, &memory))
			return (1);
		ft_cpy(line, buffer);
	}
	return (!ret && ft_strlen(*line) > 0 ? 1 : ret);
}