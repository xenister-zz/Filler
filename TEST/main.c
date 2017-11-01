
#include <stdio.h>
#include "../LibftXen/libft.h"

#define UC unsigned char

void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t c;

    c = len;
    if (src <= dst)
        while (c--)
            ((UC *)dst)[c] = ((UC *)src)[c];
    else
    {
        c = 0;
        while (c < len)
        {
            ((UC *)dst)[c] = ((UC *)src)[c];
            c++;
        }
    }
    return (dst);
}

int     main(void)
{
    char    *s1;
    char    *s2;


    s1 = ft_strdup("patate", 0);
    s2 = ft_strdup("poundai", 0);
    ft_memmove(&s1[2], s1, 4);
    printf("s = %s\n", s1);
    printf("s = %s\n", s2);
    return (0);
}