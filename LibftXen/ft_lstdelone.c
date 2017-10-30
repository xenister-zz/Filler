/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:01:03 by susivagn          #+#    #+#             */
/*   Updated: 2016/11/25 15:13:43 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*ft_del)(void*, size_t))
{
	if (!alst)
		return ;
	else
	{
		ft_del((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
	}
}
