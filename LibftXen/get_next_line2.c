/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:53:17 by susivagn          #+#    #+#             */
/*   Updated: 2017/10/30 17:56:18 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strclen(const char *s, char c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i);
}

char *ft_strnew(size_t size, char c)
{
    return (ft_memalloc((size + 1), c));
}

void *ft_memalloc(size_t size, char c)
{
    void *mem;

    if (!(mem = malloc(size)))
        return (NULL);
    ft_memset(mem, c, size);
    return (mem);
}

char *ft_append(char *s1, char *s2, int b)
{
    int c;
    char *str;

    str = NULL;
    if (!s1 && !s2)
        return (str);
    c = (ft_strlen(s1) + ft_strlen(s2));
    str = ft_strnew(c, '\0');
    if (!str)
        return (NULL);
    c = 0;
    str = ft_strcpy(str, s1);
    str = ft_strncat(str, s2, ft_strlen(s2));
    if (b == 1)
        free(s1);
    if (b == 2)
        free(s2);
    return (str);
}

void ft_delstructlst(t_list **lst, int fd)
{
    t_list *pre;
    t_list *actu;

    actu = (*lst);
    while (actu && (pre = actu) && ((t_lol *)(actu)->content)->fdi != fd)
        actu = (actu)->next;
    if (actu)
    {
        free(actu->content);
        if (actu->next != NULL && pre != actu)
        {
            pre->next = actu->next;
            actu->next = NULL;
        }
        else if (pre == actu)
        {
            (*lst) = NULL;
            actu->next = NULL;
        }
        else
            pre->next = NULL;
        free(actu);
    }
}

int ft_organise(t_lol *buffer, char **line)
{
    char *tmp;
    int c;
    int d;

    c = 0;
    d = 0;
    if (((c = ft_strclen(BB, '\n')) && (ft_strchr(BB, '\n'))) || BB[0] == '\n')
    {
        tmp = ft_strsub(BB, 0, c);
        *line = ft_append(*line, tmp, 1);
        free(tmp);
        ft_memmove(BB, &BB[c + 1], ft_strlen(BB) - c);
        d = 1;
    }
    else
    {
        *line = ft_append(*line, BB, 1);
        BB[0] = '\0';
    }
    return (d);
}

int ft_getline(t_lol *buffer, char **line, int fd)
{
    int n;
    int d;

    n = 1;
    *line = ft_strnew(0, '\0');
    buffer->fdi = fd;
    d = ft_organise(buffer, line);
    while (d == 0 && (n = read(fd, BB, BUFF_SIZE)))
    {
        if (n <= 0)
            return (n);
        BB[n] = '\0';
        if (ft_strchr(BB, '\n'))
            d = ft_organise(buffer, line);
        else
        {
            *line = ft_append(*line, BB, 1);
            BB[0] = '\0';
        }
        if (n < BUFF_SIZE)
            break;
    }
    n = (n == 0 && d == 0) ? ft_strlen(*line) : n;
    return (n);
}

int get_next_line(const int fd, char **line)
{
    static t_list *base;
    t_list *navi;
    t_lol *rest;
    int n;
    int fdr;

    rest = 0;
    if (fd < 0 || !line)
        return (-1);
    navi = base;
    while (navi && NCF != fd)
        navi = NX;
    if (!navi)
    {
        rest = ft_memalloc(sizeof(*rest), '\0');
        rest->buff[0] = '\0';
        ft_lstadd(&base, (navi = ft_lstnew(rest, sizeof(*rest))));
        free(rest);
    }
    n = ft_getline((t_lol *)navi->content, line, fd);
    if (n == -1 || n == 0)
    {
        ft_delstructlst(&base, fd);
        fdr = open("./pataponey", O_CREAT | O_RDWR | O_APPEND, 0666);
        dprintf(fdr, "n fail ===== %d\n", n);
        return (n);
    }
    fdr = open("./patapon", O_CREAT | O_RDWR | O_APPEND, 0666);
    dprintf(fdr, "n ===== %d\n", n);
    return (n = (n > 0) ? 1 : n);
}