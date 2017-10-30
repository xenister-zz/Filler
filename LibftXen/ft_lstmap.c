/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:00:49 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/16 18:24:16 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*tmplist;
	t_list	*savelist;

	if (!(lst) || !(f))
		return (NULL);
	savelist = f(lst);
	nlist = ft_lstnew(savelist->content, savelist->content_size);
	if (!(nlist))
		return (NULL);
	tmplist = nlist;
	lst = lst->next;
	while (lst)
	{
		savelist = f(lst);
		tmplist->next = ft_lstnew(savelist->content, savelist->content_size);
		if (!(tmplist))
			return (NULL);
		tmplist = tmplist->next;
		lst = lst->next;
	}
	return (nlist);
}
