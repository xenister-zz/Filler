/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:48 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/10 18:44:15 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char        **ft_addtable(char **table, char *toadd)
{
    int     i;

    i = 0;
    ft_putstr("Strat addtable\n");
    if (!toadd)
        return (table);
    if (!table)
    {
        table = ft_memalloc((sizeof(char**)), '\0');
        table[0] = ft_strdup(toadd, 0);
        table[1] = NULL;
    }
    else
    {
        while (table[i])
            i++;
        printf("i === %d\n", i);
        if (!table[i])
        {
            table[i] = ft_memalloc((sizeof(char*)), '\0');
            table[i] = ft_strdup(toadd, 0);
            table[i + 1] = NULL;
        }
    }
    ft_putstr("Ned addtable\n");
    return (table);
}

int        ft_print_table(char **table, int newline)
{
    int     i;

    i = 0;
    if (!table)
    {
        ft_putstr("Nonexistent Table\n");
        return (i);
    }
    if (newline == 0)
    {
        while (table[i])
        {
            ft_putstr(table[i]);
            i++;
        }
    }
    else if (newline == 1)
    {
        while (table[i])
        {
            ft_putendl(table[i]);
            i++;
        }
    }
    return (i);
}