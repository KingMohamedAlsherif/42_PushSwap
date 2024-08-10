/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:37:35 by kingmohamed       #+#    #+#             */
/*   Updated: 2024/08/10 20:05:05 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int      check_syntax(char  *num)
{
    int i;
    
    i = 0;
    if (!((num[i] == '+' || num[i] == '-') || (num[i] >= '0' && num[i] <= '9') || num[i] == ' ' || num[i] == '\t'))
        print_error();
    i++;
    if ((num[i] == '+' || num[i] == '-') && !(num[1] >= '0' && num[1] <= '9'))
        print_error();
    while (num[i])
    {
        if ((num[i] == '-' && num[i+1] == '-') || (num[i] == '+' && num[i+1]))
            print_error();
        if (!((num[i] >= '0' && num[i] <= '9') || (num[i] == ' ' || num[i] == '\t')
            || (num[i] == '-' || num[i] == '+')))
            print_error();
        i++;
    }
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
            si = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        if (si == 1 && res > INT_MAX)
            return 0; 
        else if (si == -1 && -res < INT_MIN)
            return 0; 
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
    t_stack_node    *current;
    
    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        current->num = 0;
        free(current);
        current = current->next;
    }
    *stack = NULL;
}

int    free_errors(t_stack_node    *a, t_stack_node    *b)
{
    if (a)
        free_stack(&a);
    if (b)
        free_stack(&b);
    return (write(2, "Erorr", 6), 1);
    exit(1);
}

int    print_error(void)
{
    return(write(2, "Error", 6), 1);
}