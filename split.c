/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:21:01 by kingmohamed       #+#    #+#             */
/*   Updated: 2024/08/10 18:39:55 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node  *split(char*    str)
{
    int i;
    int j;
    int inx;
    char *num;
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
        new_node = creat_node(num);
        free(num);
        if (!new_node)
        {
            return (NULL);
        }
        append_list(&list, new_node);
        if (str[i])
            i++;
    }
    return (list);
}
