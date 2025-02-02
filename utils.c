/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmohamedalsherif <kingmohamedalsherif@s +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:41:58 by malsheri          #+#    #+#             */
/*   Updated: 2024/08/13 14:56:59 by kingmohamedalshe ###   ########.fr       */
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

t_stack_node	* creat_node(char *str)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		free(new_node);
	new_node->next = NULL;
	new_node->num = ft_atol(str);
	return (new_node);
}

int	void_spaces(char** num)
{
	int	i;
	int j;

	j = -1;
	while(num[++j])
	{
		i = -1;
		while (num[j][++i])
		{
			if ((num[j][i] >= '0' && num[j][i] <= '9'))
				break ;
		}
		if (num[j][i] == '\0')
			return (0);
	}
	return (1);
}