/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmohamedalsherif <kingmohamedalsherif@s +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:37:35 by kingmohamedalshe  #+#    #+#             */
/*   Updated: 2024/08/05 13:44:27 by kingmohamedalshe ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     check_syntax(char  *num)
{
    int i;
    int tmp;

    i = 0;
    if (!((num[i] == '+' || num[i] == '-') || (num[i] >= '0' && num[i] <= '9') || num[i] == ' ' || num[i] == '\t'))
        return (printf("It's Not Number1"), 1);
    i++;
    if ((num[i] == '+' || num[i] == '-') && !(num[1] >= '0' && num[1] <= '9'))
        return (printf("It's Not Number2"), 1);
    while (num[i])
    {
        if (!((num[i] >= '0' && num[i] <= '9') || (num[i] == ' ' || num[i] == '\t')))
            return (printf("It's Not Number3"), 1);// change as subject request (print Error on stderror)
        i++;
    }
    printf("in Check :%s\n", num);
    check_max_min(ft_atoi(num));
    return (0);
}

int     check_max_min(int  num)
{
    if (num > 2147483647 || num < -2147483647)
        return (printf("UnInvalied Input"), 1);
    return (0);
}

// void ft_check_args(int ac, char **av)
// {
//     int i;
//     long tmp;
//     char **args;

//     i = 0;
//     if (ac == 2)
//         args = ft_split(av[1], ' ');
//     else
//     {
//         i = 1;
//         args = av;
//     }
//     while (args[i])
//     {
//         tmp = ft_atoi(args[i]);
//         if (!ft_isnum(args[i]))
//             ft_error("Error");
//         if (tmp < -2147483648 || tmp > 2147483647)
//             ft_error("Error");
//         i++;
//     }
// }


// int     check_dup(t_stack_node *a, int n)
// {
//     if (!a)
//         return (0);
//     while(a)
//     {
//         if (a->num == n)
//             return (1);
//         a = a->next;
//     }
//     return (1);
// }

int check_dup(t_list *num, int n)
{
    t_list      *tmp;

    
    if (!num)
        return (0);
    while (tmp)
    {
        if (tmp->n == n)
            return (1);
        tmp= tmp->next;
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
int    check_list(t_list   *list)
{
    t_list  *tmp;

    tmp = list;
    while (tmp)
    {
        // if (!ft_isnum(args[i]))
        //     ft_error("Error");
        printf("N : %d\n", tmp->n);
        if (tmp->n < -2147483648 || tmp->n > 2147483647)
            return(printf("MAX/MIN Error"), 1);
        tmp = tmp->next;
    }
    return (0);
}