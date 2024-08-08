/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmohamedalsherif <kingmohamedalsherif@s +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:21:01 by kingmohamedalshe  #+#    #+#             */
/*   Updated: 2024/08/07 13:21:02 by kingmohamedalshe ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node  *split(char*    str)
{
    int i;
    int j;
    int inx;
    char *num;
    int tmp;
    t_stack_node *new_node;
    t_stack_node *list;

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
