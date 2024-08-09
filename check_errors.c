/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:37:35 by kingmohamed       #+#    #+#             */
/*   Updated: 2024/08/09 14:28:13 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int      check_syntax(char  *num)
{
    int i;
    int tmp;
    int si;

    i = 0;
    if (!((num[i] == '+' || num[i] == '-') || (num[i] >= '0' && num[i] <= '9') || num[i] == ' ' || num[i] == '\t'))
        return (printf("It's Not Number1"), 1);
    i++;
    if ((num[i] == '+' || num[i] == '-') && !(num[1] >= '0' && num[1] <= '9'))
        return (printf("It's Not Number2"), 1);
    while (num[i])
    {
        if ((num[i] == '-' && num[i+1] == '-') || (num[i] == '+' && num[i+1]))
            return (printf("Too many sings"));
        if (!((num[i] >= '0' && num[i] <= '9') || (num[i] == ' ' || num[i] == '\t')
            || (num[i] == '-' || num[i] == '+')))
            return (printf("It's Not Number3"), 1);// change as subject request (print Error on stderror)
        i++;
    }
        
    // check_max_min(ft_atoi(num));
    return (0);
}

int     check_max_min(char  *str)
{
    int si;
    long long res = 0;

    si = 1;
    while (*str == ' ' || *str == '\t' )
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
        {
            si = -1;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        if (si == 1 && res > INT_MAX)
        {
            return 0; 
        }
        else if (si == -1 && -res < INT_MIN)
        {
            return 0; 
        }
        str++;
    }
    return 1;
}

int check_dup(t_stack_node *list)
{
    t_stack_node *first;
    t_stack_node *second;

    first = list;
    while (first)
    {
        second = first->next;
        while (second)
        {
            if (first->num == second->num)
                return (0);
            second = second->next;
        }
        first = first->next;
    }
    return (1);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp;
    t_stack_node    *current;
    
    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        current->next = tmp;
        current->num = 0;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void    free_errors(t_stack_node    **stack)
{
    free(stack);
    printf("Error Found");
    exit(0);
}