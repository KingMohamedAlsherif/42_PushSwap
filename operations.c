#include "push_swap.h"

static  void    swap(t_stack_node   **head)
{
    if(!*head || !(*head)->next)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}

void    sa(t_stack_node **a, bool    print)
{
    swap(a);
    if(!print)
        printf("sa\n");
}

void    sb(t_stack_node **b, bool    print)
{
    swap(b);
    if(!print)
        printf("sb\n");
}

void    ss(t_stack_node **a, t_stack_node   **b, bool   print)
{
    swap(a);
    swap(b);
    if(!print)
        printf("ss\n");
}

static  void    rotate(t_stack_node **stack)
{
    t_stack_node    *last;

    if(!*stack || !(*stack)->next)
        return;
    last = find_last(*stack);
    last->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        printf("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (!print)
        printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node   **b, bool   print)
{
    rotate(a);
    rotate(b);
    if (!print)
        printf("rr\n");
}


static  void    rev_rotate(t_stack_node **stack)
{
    t_stack_node    *last;

    if (!*stack || !(*stack)->next)
        return;
    last = find_last(*stack);
    last->next->prev = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev = last;
}

void    rra(t_stack_node    **a, bool print)
{
    rev_rotate(a);
    if (!print)
        printf("rra\n");
}

void rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if (!print)
        printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node  **b, bool print)
{
    rev_rotate(a);
    reve_rotate(b);
    if (!print)
        printf("rrr\n");
}