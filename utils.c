#include "push_swap.h"

bool    stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while(stack->next)
    {
        if (stack->num > stack->next->num)
            return (false);
        stack = stack->next;
    }
    return (true);
}

t_list *find_last(t_list *list)
{
    if (NULL == list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

void    append_list(t_list **list, t_list *new_node)
{
    t_list *last;

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

void     print_list(t_list   *list)
{
    t_list  *tmp;

    tmp = list;
    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

t_list  *creat_node(char *str)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (printf("Error in new node"), NULL);
    new_node->next = NULL;
    new_node->n = ft_atoi(str);
    return (new_node);
}

int ft_atoi(const char *str)
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
