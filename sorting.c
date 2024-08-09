/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmohamedalsherif <kingmohamedalsherif@s +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:01:12 by kingmohamedalshe  #+#    #+#             */
/*   Updated: 2024/08/08 20:26:49 by kingmohamedalshe ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort_three(t_stack_node **a) // Define a function that handles when stack `a` has three nodes, and sorts it
// {
// 	t_stack_node *biggest_node; // To store a pointer to the biggest node in stack `a`

// 	printf("anything");
// 	biggest_node = find_max(*a);
// 	printf("hoh");
// 	if (!biggest_node)
// 		return;
// 	if (biggest_node == *a)				 // Check if the current node is the biggest
// 		ra(a, false);
// 	else if ((*a)->next == biggest_node) // Check if the second node is the biggest
// 		rra(a, false);					 // If so, reverse rotate the bottom node, to the top of the stack
// 	if ((*a)->num > (*a)->next->num)	 // Check if the bottom node is the biggest, but the top node is higher than the second node
// 		sa(a, false);					 // If so, simply swap the top and second nodes
// }

// static	t_stack_node *find_max(t_stack_node **stack)
// {
// 	long	 max;
// 	t_stack_node *max_node;
// 	t_stack_node *tmp;

// 	tmp = *stack;
// 	if (!tmp)
// 		return (NULL);
// 	max = LONG_MIN;
// 	max_node = tmp;
// 	while (tmp)
// 	{
// 		if (tmp->num > max)
// 		{
// 			max = tmp->num;
// 			max_node = tmp;
// 		}
// 		tmp = tmp->next;
// 	}
// 	printf("Max is : max");
// 	return (max_node);
// }

void sort_three(t_stack_node **a) // Define a function that handles when stack `a` has three nodes, and sorts it
{
	t_stack_node *biggest_node; // To store a pointer to the biggest node in stack `a`

	biggest_node = find_max(*a);
	if (biggest_node == *a)				 // Check if the current node is the biggest
		ra(a, false);					 // If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) // Check if the second node is the biggest
		rra(a, false);					 // If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->num > (*a)->next->num)	 // Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a, false);					 // If so, simply swap the top and second nodes
}

// void sort_three(t_stack_node **a)
// {
// 	t_stack_node *biggest;
// 	t_stack_node	*tmp;

// 	tmp = *a;
// 	printf("big\n");
// 	biggest = find_max(tmp);
// 	if (!biggest)
// 		printf("big : %d", biggest->num);
// 	if (biggest == tmp)
// 		ra(a, false);
// 	else if (tmp->next == biggest)
// 	{
// 		printf("second is biggest");
// 		rra(a, false);
// 	}
// 	if (tmp->inx > tmp->next->inx)
// 	{
// 		sa(a, false);
// 	}
// }

void	radix_sort_stack_b(t_stack_node *b, t_stack_node	*a, int	bit_size, int j)
{
	t_stack_node	*tmp;
	int 		b_size;

	tmp = b;
	b_size = count_list(b);
	printf("Im here in sort b");
	while (b_size-- && j <= bit_size && !stack_sorted(tmp))
	{
		if (((tmp->inx >> j) & 1) == 0)
			rb(&b , false);
		else
			pa(&a, &b, false);
	}
	if(stack_sorted(b))
	{
		while(b_size != 0)
			pa(&a, &b, false);
	}
}

void	radix_sorting(t_stack_node	*a, t_stack_node	*b)
{
	int 			j;
	t_stack_node	*tmp;
	int 			bit_size;
	int size;

	tmp = a;
	print_list(tmp);
	bit_size = 0;
	size = count_list(tmp);
	while(size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = count_list(tmp);
		while (size-- && !stack_sorted(a))
		{
			tmp = a;
			if (((tmp->inx >> j) & 1) == 0)
				pb(&b, &a, false);
			else
				ra(&a , false);
			printf("size :%d\n", size);
			printf("inx :%d\n", tmp->inx);
		}
		radix_sort_stack_b(b, a, bit_size, j + 1);
	}
	while(b)
		pa(&a, &b, false);
}

// void sort_four_to_five_elements(t_stack_node *a, t_stack_node	*b)
// {
// 	t_stack_node	*tmp_a;
// 	t_stack_node 	*tmp_b;

// 	tmp_a = a;
// 	while (tmp_b <= 1)
// 	{
// 		if (tmp_a->inx == 0 || tmp_a->inx == 1)
// 			push(a, b);
// 		else
// 			rotate(a);
// 	}
// 	if (tmp_b == 0)
// 		swap(b);
// 	if (tmp_a->inx != 4)
// 	{
// 		if (tmp_a->inx == 4)
// 			ra(a, false);
// 		else
// 			rra(a, false);
// 	}
// 	if (tmp->inx > s->a[1])
// 		sa(a, false);
// 	pa(a);
// 	pa(a);
// }