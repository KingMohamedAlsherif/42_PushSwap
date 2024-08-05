#include "push_swap.h"

// static int  count_words(char* s, char c)
// {
//     int count;
//     bool inside;

//     count = 0;
//     while(*s)
//     {
//         inside = false;
//         if (*s == c)
//             ++s;
//         while(*s != c && *s)
//         {
//             if(!inside)
//             {
//                 ++count;
//                 inside = true;
//             }
//             ++s;
//         }
//     }
//     return (count);
// }

// static  char    get_next_word(char  *s, char    c)
// {
//     static int cursor = 0;
//     char *next_word;
//     int len;
//     int i;

//     len = 0;
//     i = 0;
//     while(s[cursor] == c)
//         cursor++;
//     while((s[cursor + len] != c) && (s[cursor + len]))
//         ++len;
//     next_word = malloc((size_t)len * sizeof(char) + 1);
//     if (!next_word)
//         return (NULL);
//     while((s[cursor] != c) && s[cursor])
//         next_word[i++] = s[cursor++];
//     next_word[i] = '\0';
//     return (next_word);
// }

// t_list    *split(char    *s, char    c)
// {
//     int     count;
//     char    **res;
//     int     i;

//     i = 0;
//     count = count_words(s, c);
//     if (!count)
//         exit (1);
//     new_node = malloc(sizeof(char *) * (size_t)(count + 2));
//     if (!res)
//         return (NULL);
//     while(count-- >= 0)
//     {
//         if (i == 0)
//         {
//             res[i] = malloc(sizeof(char));
//             if (!res[i])
//                 return (NULL);
//             res[i++] = '\0';
//             continue;
//         }
//         res[i++] = get_next_word(s, c);
//     }
//     res[i] = NULL;
//     return (res);
// }

t_list  *split(char*    str)
{
    int i;
    int j;
    int inx;
    char *num;
    int tmp;
    t_list *new_node;
    t_list *list;

    i = 0;
    j = 0;
    inx = 0;
    list = NULL;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        j = i;
        while (str[i] && (str[i] != ' ' && str[i] != '\t'))
            i++;
        // printf("i = %d and j = %d\n", i, j);
        num = malloc(sizeof(char) * (i - j) + 1);
        if (!num)
            return (printf("Error in str"), NULL);
        while (j < i)
        {
            num[inx] = str[j];
            j++;
            inx++;
        }
        num[inx] = '\0';
        inx = 0;
        // write(1, num, strlen(num));
        // write(1, "\n", 1);
        new_node = creat_node(num);
        free(num);
        if (!new_node)
        {
            // free_list(list);
            return (NULL);
        }
        append_list(&list, new_node);
        if (str[i])
            i++;
    }
    // printf("in split\n");
    // print_list(list);
    return (list);
}
