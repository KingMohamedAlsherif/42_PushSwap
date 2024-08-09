#include "push_swap.h"

// void sort_four_to_five(t_stack_node **a, t_stack_node	**b)
// {
// 	t_stack_node	*tmp_a;
// 	t_stack_node 	*tmp_b;
// 	int				size_b;
	
	
// 	tmp_a = *a;
// 	tmp_b = *b;
// 	size_b = count_list(*b);
// 	while (size_b-- <= 1)
// 	{
// 		if (tmp_a->inx == 0 || tmp_a->inx == 1)
// 			push(a, b);
// 		else
// 			rotate(a);
// 	}
// 	if (tmp_b == 0)
// 		sb(b, false);
// 	if (tmp_a->inx != 4)
// 	{
// 		if (tmp_a->inx == 4)
// 			ra(a, false);
// 		else
// 			rra(a, false);
// 	}
// 	if (tmp_b->inx > tmp_b->next->inx)
// 		sa(a, false);
// 	pa(a , b, false);
// 	pa(a, b, false);
// }

// void    sort_three(t_stack_node **a)
// {
//     t_stack_node *biggest;

//     biggest = find_max(*a);
//     if (biggest == *a)
//         ra(a, false);
//     else if(biggest == (*a)->next)
//         rra(a, false);
//     if  ((*a)->num > (*a)->next->num)
//         sa(a, false);
// } 

void    sort_four_or_five(t_stack_node  **a, t_stack_node   **b)
{
    t_stack_node    *tmp;

    tmp = *a;
    if (!tmp)
        return;
    while(count_list(a) == 2)
    {
        if ((*a) == 0 || *(a) == 1)
            pb(b, a, false);
        else
            ra(a, false);
    }
    if (stack_sorted(b))
        sb(b, false);
    sort_three(a);
    if (stack_sorted(a))
        {
            while(b)
                pa(a, b, false);
        }
}