/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 07:40:10 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/11 08:05:44 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	last = find_last(tmp);
	last->next = tmp;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = last;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}
