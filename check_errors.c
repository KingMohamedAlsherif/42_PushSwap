/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 07:36:51 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/12 09:04:12 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *num)
{
	int	i;

	i = 0;
	if (!((num[i] == '+' || num[i] == '-') || (num[i] >= '0' && num[i] <= '9')
			|| num[i] == ' ' || num[i] == '\t'))
		print_error();
	i++;
	if ((num[i] == '+' || num[i] == '-') && !(num[1] >= '0' && num[1] <= '9'))
		print_error();
	while (num[i])
	{
		if ((num[i] == '-' && num[i + 1] == '-') || (num[i] == '+' && num[i
					+ 1] == '+'))
			print_error();
		if (!((num[i] >= '0' && num[i] <= '9') || (num[i] == ' '
					|| num[i] == '\t') || (num[i] == '-' || num[i] == '+')))
			print_error();
		i++;
	}
	return (0);
}

int	check_max_min(char *str)
{
	int			si;
	long long	res;

	res = 0;
	si = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			si = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (si == 1 && res > INT_MAX)
			return (0);
		else if ((si == -1) && (-res < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->num = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	free_errors(t_stack_node **a, t_stack_node **b)
{
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
	write(2, "Erorr\n", 7);
	exit(1);
}

int	print_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}
