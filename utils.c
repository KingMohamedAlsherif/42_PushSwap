/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:41:58 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/10 18:41:59 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    stack_sorted(t_stack_node *stack)
{
    t_stack_node    *tmp;

    tmp = stack;
    if (!tmp)
        return (1);
    while(tmp->next)
    {
        if (tmp->num > tmp->next->num)
            return (0);
        tmp = tmp->next;
    }
    return (true);
}

t_stack_node *find_last(t_stack_node *list)
{
    if (NULL == list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

void    append_list(t_stack_node **list, t_stack_node *new_node)
{
    t_stack_node *last;

    if (!(*list))
    {
        *list = new_node;
        new_node->prev = NULL;
    }
    else
    {
        last = find_last(*list);
        last->next = new_node;
        new_node->prev = last;
    }
}

void     print_list(t_stack_node   *list)
{
    t_stack_node  *tmp;

    if (!list || !(list)->next)
        return ;
    tmp = list;
    while (tmp)
    {
        printf("(%d - Inx => %d) ", tmp->num, tmp->inx);
        tmp = tmp->next;
    }
    printf("\n");
}

t_stack_node  *creat_node(char *str)
{
    t_stack_node *new_node;

    new_node = malloc(sizeof(t_stack_node));
    if (!new_node)
        return (printf("Error in new node"), NULL);
    new_node->next = NULL;
    new_node->num = atoi(str);
    return (new_node);
}

long ft_atol(const char *str)
{
    int si;
    unsigned long long num;

    si = 1;
    num = 0;
    while (((*str >= 9 && *str <= 13) || *str == ' '))
        str++;
    if (*str == '-')
    {
        si = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str != 0 && *str >= 48 && *str <= 57)
    {
        num = (num * 10) + (*str - 48);
        str++;
    }
    if (num >= 9223372036854775807ULL && si == 1)
        return (-1);
    if (num >= 9223372036854775807ULL && si == -1)
        return (0);
    return (num * si);
}

size_t  count_words(char const *s, char c)
{
    size_t words;
    size_t i;

    words = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
            words++;
        i++;
    }
    return (words);
}

int     count_list(t_stack_node *stack)
{
    t_stack_node    *tmp;
    int count;

    count = 0;
    tmp = stack;
    while(tmp)
    {
        tmp = tmp->next;
        count++;
    }
    return (count);
}

void     indexing(t_stack_node   *stack)
{
    t_stack_node    *tmp1;
    t_stack_node    *tmp2;
    int inx;

    tmp1 = stack;
    while (tmp1)
    {
        tmp2 = stack;
        inx = 0;
        while (tmp2)
        {
            if (tmp1->num > tmp2->num)
                inx++;
            tmp1->inx = inx;
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
}

t_stack_node *find_max(t_stack_node *stack) 
{
    long max;               
    t_stack_node *max_node; 

    if (!stack)
        return (NULL);
    max = LONG_MIN; 
    while (stack)   
    {
        if (stack->num > max) 
        {
            max = stack->num;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}