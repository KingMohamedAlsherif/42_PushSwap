#include "push_swap.h"

bool    stack_sorted(t_stack_node *stack)
{
    t_stack_node    *tmp;

    tmp = stack;
    if (!tmp)
        return (1);
    while(tmp->next)
    {
        if (tmp->num > tmp->next->num)
        {
            printf("Break Point : %d\n", tmp->num);
            return (false);
        }
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

    tmp = list;
    while (tmp)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->next;
    }
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
