/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:48 by susivagn          #+#    #+#             */
/*   Updated: 2017/11/11 21:03:58 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char        **ft_addtable(char **table, char *toadd, int size)
{
    int     i;

    i = 0;
    ft_putstr("Strat addtable\n");
    ft_putendl(toadd);
    if (!toadd)
        return (table);
    if (!table)
    {
        printf("***je creer***\n");
        table = (char**)ft_memalloc((size + 1) * (sizeof(char*)), '\0');
        table[size] = NULL;
    }
    while(table[i] && (table[i][0] != '\0'))
        i++;
    table[i] = toadd;
    printf("i = %d\n", i);
    printf("%s", table[i]);
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
