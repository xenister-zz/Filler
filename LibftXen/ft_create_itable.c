/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_itable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:17:39 by susivagn          #+#    #+#             */
/*   Updated: 2017/12/06 18:53:07 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int **ft_create_itable(int size1, int size2)
{
    int **table;
    int i;

    i = 0;
    table = NULL;
    table = (int **)ft_memalloc(size1 * (sizeof(int *)), '\0');
    while (table[i])
    {
        table[i] = ft_memalloc(size2 * (sizeof(int)), '\0');
        i++;
    }
    return (table);
}
