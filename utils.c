/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:41:58 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/11 07:35:12 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *stack)
{
	t_stack_node	*tmp;

	tmp = stack;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (true);
}

t_stack_node	*find_last(t_stack_node *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	append_list(t_stack_node **list, t_stack_node *new_node)
{
	t_stack_node	*last;

	if (!(*list))
	{
		*list = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = find_last(*list);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	print_list(t_stack_node *list)
{
	t_stack_node	*tmp;

	if (!list || !(list)->next)
		return ;
	tmp = list;
	while (tmp)
	{
		printf("(%d - Inx => %d) ", tmp->num, tmp->inx);
		tmp = tmp->next;
	}
	printf("\n");
}

t_stack_node	*creat_node(char *str)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (printf("Error in new node"), NULL);
	new_node->next = NULL;
	new_node->num = atoi(str);
	return (new_node);
}
