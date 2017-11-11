
// #include <stdio.h>
// #include "../LibftXen/libft.h"

// #define UC unsigned char

// void *ft_memmove(void *dst, const void *src, size_t len)
// {
//     size_t c;

//     c = len;
//     if (src <= dst)
//         while (c--)
//             ((UC *)dst)[c] = ((UC *)src)[c];
//     else
//     {
//         c = 0;
//         while (c < len)
//         {
//             ((UC *)dst)[c] = ((UC *)src)[c];
//             c++;
//         }
//     }
//     return (dst);
// }

// int     main(void)
// {
//     char    *s1;
//     char    *s2;


//     s1 = ft_strdup("patate", 0);
//     s2 = ft_strdup("poundai", 0);
//     ft_memmove(&s1[2], s1, 4);
//     printf("s = %s\n", s1);
//     printf("s = %s\n", s2);
//     return (0);
// }

// int get_next_line2(const int fd, char **line)
// {
//     static char *tmp;
//     char        *cpy;
//     int n;
//     int c;

//     n = 0;
//     c = 0;
//     if (fd <= 0 || !(*line) || BUFF_SIZE <= 0)
//         return (-1);
//     *line = ft_strnew(BUFF_SIZE + 1, '\0');
//     if (!tmp || (tmp && (ft_strclen(tmp, '\n') == -1)))
//     {
//         if (!tmp)
//             tmp = ft_strnew(BUFF_SIZE + 1, '\0');
//         if ((c = ft_strclen(tmp, '\n')) == -1)
//         {
//            *line = ft_append(*line, tmp, 1);
//         }
//         while ((n = read(fd, tmp, BUFF_SIZE)) > 0)
//         {

//             if ((c = ft_strclen(tmp, '\n')) != -1)
//             {
//                 if (c != 0)
//                 {
//                     printf("ok1\n");
//                     *line = ft_append(*line, ft_strsub(tmp, 0, c), 1);
//                     ft_memmove(tmp, &tmp[c + 1], (ft_strlen(tmp) - (c)));
//                     //tmp = ft_strdup(&tmp[c + 1], 0);
//                     return (n);
//                 }
//                 else if (c == 0)
//                 {
//                     printf("ok2\n");
//                     ft_memmove(tmp, &tmp[c + 1], (ft_strlen(tmp) - (c)));
//                     //tmp = ft_strdup(&tmp[c + 1], 0);
//                     return (n);
//                 }
//             }
//             else
//             {
//                 printf("ok3\n");
//                 *line = ft_append(*line, tmp, 1);
//             }
//         }
//     }
//     else if (tmp && ((c = ft_strclen(tmp, '\n')) != -1))
//     {
//         printf("ok4\n");
//         n = ft_strlen(tmp);
//         *line = ft_append(*line, ft_strsub(tmp, 0, c), 1);
//         //tmp = ft_strdup(&tmp[c + 1], 0);
//         ft_memmove(tmp, &tmp[c + 1], n - (c));
//     }
//     printf("TMP == %s\n", tmp);
//     return (n);
// }

// int main(void)
// {
//     char *line;
//     int fd;

//     printf("***STRAT buffsize -> %d***\n", BUFF_SIZE);
//     fd = open("./pate", O_RDWR, O_TRUNC, 0666);
//     while (get_next_line2(fd, &line) > 0)
//         printf("s = %s\n", line);
//     free(line);
//     return (0);
// }

#include <unistd.h>
#include "../LibftXen/libft.h"

int main(int argc, char **argv)
{
    char    **tabel;
    char    *str;
    char    *str2;
    
    tabel = NULL;
    str = ft_strdup("un string pas comme les autre", 0);
    str2 = ft_strdup("un string comme les autre", 0);
    tabel = ft_addtable(tabel, "kgsdfjl jjlvsd sdoifjsdfs", 9);
    tabel = ft_addtable(tabel, "kgsdfjl jjlvsd sdoifjsdfs", 2);
    tabel = ft_addtable(tabel, "kgsdfjl jjlvsd sdoifjsdfs", 2);
    tabel = ft_addtable(tabel, "kgsdfjl jjlvsd sdoifjsdfs", 2);
    tabel = ft_addtable(tabel, "kgsdfjl jjlvsd sdoifjsdfs", 2);
    tabel = ft_addtable(tabel, "kgsdfjl jjlvsd sdoifjsdfs", 2);
    tabel = ft_addtable(tabel, "kgsdfjl jjlvsd sdoifjsdfs", 2);
    tabel = ft_addtable(tabel, str, 2);
    tabel = ft_addtable(tabel, str2, 2);
    free(str);
    printf("dfs = = %s", str);
    ft_print_table(tabel, 1);
    return (0);
}