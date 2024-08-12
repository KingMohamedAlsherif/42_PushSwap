/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 07:34:33 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/12 06:57:34 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int					si;
	unsigned long long	num;

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

int	count_list(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				count;

	count = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	indexing(t_stack_node *stack)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;
	int				inx;

	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = stack;
		inx = 0;
		while (tmp2)
		{
			if (tmp1->num > tmp2->num)
				inx++;
			tmp1->inx = inx;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	check_dup(t_stack_node *list)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = list;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->num == second->num)
				return (0);
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}
