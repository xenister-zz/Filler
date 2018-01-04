/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addinttable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:48 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/04 17:26:16 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int        **ft_addinttable(int **table, int *toadd, int size, int size2)
{
    int     i;

    i = 0;
    if (!toadd)
        return (table);
    if (!table)
    {
        table = (int**)ft_memalloc((size + 1) * (sizeof(int*)), 0);
        table[size] = NULL;
    }
    while(table[i] && i < size2)
        i++;
    table[i] = toadd;
    return (table);
}
