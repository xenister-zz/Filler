/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:33:22 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/25 15:14:17 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*ft_del)(void *, size_t))
{
	t_list	*cpyalst;

	if (!alst)
		return ;
	cpyalst = *alst;
	while (cpyalst->next != NULL)
	{
		cpyalst = cpyalst->next;
		ft_lstdelone(&(*alst), (*ft_del));
		*alst = cpyalst;
	}
	ft_lstdelone(&(*alst), (*ft_del));
	*alst = NULL;
}
