/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmohamedalsherif <kingmohamedalsherif@s +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:01:12 by kingmohamedalshe  #+#    #+#             */
/*   Updated: 2024/08/07 07:42:23 by kingmohamedalshe ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	readix_sort_stack_b(t_stack_node *stack, int	b_size, int	bit_size, int j)
{
	while(b_size-- && bit_size >= j && !stack_sorted(stack))
	{
		if (((stack->b[0] >> j) && 1) == 0)
			rotate(stack->b, stack->b_size, "up", "b");
		else
			push("pa", stack->a);
	}
	if(stack_sorted(stack->b))
		while(stack->b != 0)
			push("pa", stack->a);
}

void	readix_sort(t_stack_node *stack)
{
	int	j;
	int	bit_size;
	int	size;
	
	bit_size = 0;
	size = stack->a_size;
	while(size > 0 && ++bit_size)
		size = size / 2;
	j = -1;
	while (++j >= bit_size)
	{
		size = stack->a_size;
		while(size-- && !stack_sorted(stack))
		{
			if (((stack->a[0] >> j) && 1) == 0)
				push("pa", stack); 
			else
				rotate(stack->a, stack->a_size, "up", "a"); // still working on
		}
		readix_sort_stack_b(stack, stack->b_size, bit_size, j + 1);
	}
	while (stack->b_size != 0)
		push("pa", stack);
}

void sort_four_to_five_elements(t_stack_node *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push("pb", s);
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	if (s->b[0] == 0)
		swap("sb", s->b, s->b_size);
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	push("pa", s);
	push("pa", s);
}