/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 08:39:40 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/11 10:34:17 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	main_check(int ac, char **av)
{
	int	j;

	j = 1;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac >= 2)
	{
		while (av[j])
		{
			if (!check_max_min(av[j]))
				print_error();
			if (check_syntax(av[j]))
				return (1);
			j++;
		}
	}
	return (0);
}

static	void	main_sort(t_stack_node	*a, t_stack_node	*b)
{
	int	count;

	count = 0;
	indexing(a);
	count = count_list(a);
	if (count == 2)
		sa(&a, false);
	else if (count == 3)
		sort_three(&a);
	else if (count_list(a) == 4 || count_list(a) == 5)
		sort_four_or_five(&a, &b);
	else
		radix_sorting(&a, &b);
}

static	void	check_again(t_stack_node	*a, t_stack_node	*b)
{
	if (!check_dup(a))
		free_errors(a, b);
	else if (stack_sorted(a))
		free_errors(a, b);
}

static	void	free_it(t_stack_node	*a, t_stack_node	*b)
{
	if (stack_sorted(a))
	{
		free_stack(&a);
		free_stack(&b);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				j;
	t_stack_node	*new_node;

	a = NULL;
	b = NULL;
	if (main_check(ac, av) == 1)
		return (1);
	j = 1;
	if (ac > 2)
	{
		while (j < ac)
		{
			new_node = split(av[j]);
			if (!new_node)
				free_errors(a, b);
			append_list(&a, new_node);
			j++;
		}
		check_again(a, b);
		main_sort(a, b);
	}
	free_it(a, b);
	return (0);
}
