/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:57:20 by susivagn          #+#    #+#             */
/*   Updated: 2017/08/10 15:48:32 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlist;

	nlist = (t_list*)malloc(sizeof(t_list));
	if (!nlist)
		return (NULL);
	if (content == NULL)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
		nlist->next = NULL;
	}
	else
	{
		nlist->content = ft_memalloc(content_size, '\0');
		nlist->content = ft_memcpy(nlist->content, content, content_size);
		nlist->content_size = content_size;
		nlist->next = NULL;
	}
	return (nlist);
}
