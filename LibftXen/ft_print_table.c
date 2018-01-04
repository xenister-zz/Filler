/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:45:19 by susivagn          #+#    #+#             */
/*   Updated: 2018/01/04 14:45:53 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int        ft_print_table(char **table, int newline)
{
    int     i;

    i = 0;
    if (!table)
    {
        ft_putstr("Nonexistent Table\n");
        return (i);
    }
    while (table[i])
    {
        if (newline == 1)
            ft_putendl(table[i]);
        else
            ft_putstr(table[i]);
        i++;
    }
    return (i);
}
