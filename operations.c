#include "push_swap.h"

// static  void    swap(t_stack_node   **head)
// {
//     if(!*head || !(*head)->next)
//         return ;
//     *head = (*head)->next;
//     (*head)->prev->prev = *head;
//     (*head)->prev->next = (*head)->next;
//     if ((*head)->next)
//         (*head)->next->prev = (*head)->prev;
//     (*head)->next = (*head)->prev;
//     (*head)->prev = NULL;
// }


void    swap(t_stack_node   **head)
{
    t_stack_node *tmp;

    tmp = *head;
    if (!*head || !(*head)->next)
        return;
    *head = (*head)->next;
    (*head)->next = tmp;
    (*head)->prev = NULL;
    tmp->prev = *head;
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

// static  void    rotate(t_stack_node **stack)
// {
//     t_stack_node    *last;

//     if(!*stack || !(*stack)->next)
//         return;
//     last = find_last(*stack);
//     last->next = *stack;
//     *stack = (*stack)->next;
//     (*stack)->prev = NULL;
//     last->next->prev = last;
//     last->next->next = NULL;
// }

// void    rotate(t_stack_node **stack)
// {
//     t_stack_node    *tmp;
//     t_stack_node    *last;

//     tmp = *stack;
//     if (!tmp || !tmp->next)
//         return ;
//     last = find_last(tmp);
//     last->next = tmp;
//     tmp = tmp->next;
//     tmp->prev = NULL;
//     tmp = last;
//     tmp->next->next = NULL;
// }

void rotate(t_stack_node **stack) // Define a function that rotates the stack's top node to the bottom of the stack
{
    t_stack_node *last_node; // To store a pointer to the last node of a stack

    if (!*stack || !(*stack)->next) // Check if the stack is empty, or if there's one node
        return;
    last_node = find_last(*stack);
    last_node->next = *stack;          // Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
    *stack = (*stack)->next;           // Assign to the pointer of the top node, the node after it (second from the top)
    (*stack)->prev = NULL;             // Complete setting the current top node by detaching it from its previous top node
    last_node->next->prev = last_node; // Reconnect the second node's prev pointer to point to what was previously the last node in the stack
    last_node->next->next = NULL;      // Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
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


// static  void    rev_rotate(t_stack_node **stack)
// {
//     t_stack_node    *last;

//     if (!*stack || !(*stack)->next)
//         return;
//     last = find_last(*stack);
//     last->next->prev = NULL;
//     last->next = *stack;
//     last->prev = NULL;
//     *stack = last;
//     last->next->prev = last;
// }

void    rev_rotate(t_stack_node **stack)
{
    t_stack_node    *last;
    t_stack_node    *tmp;

    tmp = *stack;
    if (!tmp || !tmp->next)
        return ;
    last = find_last(*stack);
    tmp = *stack;
    last->next->prev = NULL;
    last->next = tmp;
    last->prev = NULL;
    tmp = last;
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
    rev_rotate(b);
    if (!print)
        printf("rrr\n");
}

void    push(t_stack_node   **dest, t_stack_node  **src)
{
    t_stack_node    *push_node;

    if (*src)
        return;
    push_node = *src;
    if (*src)
        (*src)->prev = NULL;
    push_node->prev = NULL;
    if (!*dest)
    {
        *dest = push_node;
        push_node->next = NULL;
    }
    else
    {
        push_node->next = *dest;
        push_node->next->prev = push_node;
        *dest = push_node;
    }
}

void pa(t_stack_node **a, t_stack_node **b, bool print)
{
    push(a, b);
    if (!print)
        printf("pa\n");
}

void pb(t_stack_node **b, t_stack_node **a, bool print)
{
    push(b, a);
    if (!print)
        printf("pb\n");
}

// void    swap(char*  str, int*   array, int  size)
// {
//     int tmp;

//     if (size <= 0)
//         return;
//     array[0] = tmp;
//     array[0] = array[1];
//     array[1] = tmp;
//     printf("%s", str);
// }

// void    push(char*  str, t_stack_node   *stack)
// {
//     int tmp;

//     if(strncmp(str, "pa", 3) == 0)
//     {
//         if (stack->b_size <= 0)
//             return ;
//         tmp = stack->a[0];
//         memmove(stack->a + 1, stack->a, sizeof(int) * stack->a_size);
//         stack->a[0] = tmp;
//         stack->b_size--;
//         memmove(stack->b, stack->b + 1, sizeof(int) * stack->b_size);
//         stack->a_size++;
//     }
//     else if (strncmp(str, "pb", 3) == 0)
//     {
//         if (stack->a_size <= 0)
//             return ;
//         tmp = stack->a[0];
//         memmove(stack->b + 1, stack->b, sizeof(int) * stack->b_size);
//         stack->b[0] = tmp;
//         stack->a_size--;
//         memmove(stack->a, stack->a + 1, sizeof(int) * stack->a_size);
//         stack->b_size++;
//     }
// }

// void    rotate(int  *array, int size, char* dir, char   *list)
// {
//     int tmp;

//     if (size < 0)
//         return ;
//     if (strncmp(dir, "up", 3) == 0)
//     {
//         tmp = array[0];
//         memmove(array, array + 1, sizeof(int) * (size - 1));
//         array[size - 1] = tmp;
//         write(1, 'r', 1);
//     }
//     else if (strncmp(dir, "down", 5) == 0)
//     {
//         tmp = array[size - 1];
//         memmove(array + 1, array, sizeof(int) * (size - 1));
//         array[0] = tmp;
//         write(1, "rr", 2);
//     }
//     printf(array);
// }