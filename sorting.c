/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:01:12 by kingmohamed       #+#    #+#             */
/*   Updated: 2024/08/11 06:32:31 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	if ((*a)->inx == 2)
		ra(a, false);
	else if ((*a)->next->inx == 2)
		rra(a, false);
	if ((*a)->inx > (*a)->next->inx)
		sa(a, false);
}

void	radix_sort_stack_b(t_stack_node **b, t_stack_node **a, int bit_size,
		int j)
{
	t_stack_node	*tmp;
	int				size;

	tmp = *b;
	size = count_list(*b);
	while (size-- && j <= bit_size && !stack_sorted(tmp))
	{
		if (((tmp->inx >> j) & 1) == 0)
		{
			rb(b, false);
			tmp = *b;
		}
		else
		{
			pa(a, b, false);
			tmp = *b;
		}
	}
	if (stack_sorted(*b))
	{
		while (*b)
			pa(a, b, false);
	}
}

void	radix_sorting(t_stack_node **a, t_stack_node **b)
{
	int				j;
	t_stack_node	*tmp;
	int				bit_size;
	int				size;

	tmp = *a;
	bit_size = 0;
	size = count_list(tmp);
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		tmp = *a;
		size = count_list(tmp);
		while (size-- && !stack_sorted(*a))
		{
			if (((tmp->inx >> j) & 1) == 0)
			{
				pb(b, a, false);
				tmp = *a;
			}
			else
			{
				ra(a, false);
				tmp = *a;
			}
		}
		radix_sort_stack_b(b, a, bit_size, j + 1);
	}
	while (*b)
		pa(a, b, false);
}

void	sort_four_or_five(t_stack_node **a, t_stack_node **b)
{
	int b_size;

	while (count_list(*b) <= 1)
	{
		if ((*a)->inx == 0 || (*a)->inx == 1)
			pb(b, a, false);
		else
			ra(a, false);
	}
	if (!stack_sorted(*a))
	{
		indexing(*a);
		sort_three(a);
	}
	else if (stack_sorted(*b))
		sb(b, false);
	b_size = count_list(*b);
	if (stack_sorted(*a))
		while (b_size--)
			pa(a, b, false);
}
