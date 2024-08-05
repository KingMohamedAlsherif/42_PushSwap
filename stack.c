#include "push_swap.h"

static  long    ft_atol(const   char    *num)
{  
    long res;
    int si;
    
    res = 0;
    si = 1;
    while (*num == ' ' || *num == '\t' || *num == '\n' ||
           *num == '\r' || *num == '\f' || *num == '\v')
    if (*num == '-' || *num == '+')
    {
        if (*num == '-')
            si = -1;
        num++;
    }
    while (ft_isdigit(*num))
        res = res * 10 + (*num++ - '0');
    return (res * si);
}

static void append(t_stack_node **stack, int num)
{
    t_stack_node    *node;
    t_stack_node    *last;
    
    if(!stack)
        return ;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->next = NULL;
    node->num = num;
    if(!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last = find_last(*stack);
        last->next = node;
        node->prev = last;
    }
}

void    stack_init(t_stack_node **a, char**  av)
{
    long    num;
    int     i;

    i = 0;
    while (av[i])
    {
        if (check_syntax(av[i]))
            free_errors(a);
        num = ft(atol(av[i]));
        if (num > INT_MAX || INT_MIN)
            free_errors(a);
        if (check_dup(a, (int)num))
            free_errors(a);
        append(a, (int)num); //still
        i++;
    }
}