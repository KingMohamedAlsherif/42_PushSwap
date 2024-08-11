/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 07:41:02 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/11 08:05:39 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	last = find_last(tmp);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}
