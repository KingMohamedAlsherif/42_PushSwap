/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmohamedalsherif <kingmohamedalsherif@s +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:21:01 by kingmohamed       #+#    #+#             */
/*   Updated: 2024/08/12 17:47:14 by kingmohamedalshe ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parse_number(char *str, int *index)
{
	int		j;
	int		inx;
	char	*num;

	inx = 0;
	while (str[*index] && (str[*index] == ' ' || str[*index] == '\t'))
		(*index)++;
	j = *index;
	while (str[*index] && (str[*index] != ' ' && str[*index] != '\t'))
		(*index)++;
	// if (j == (*index))
	// 	return (NULL);
	num = malloc(sizeof(char) * (*index - j) + 1);
	if (!num)
		print_error();
	while (j < *index)
	{
		num[inx] = str[j];
		j++;
		inx++;
	}
	num[inx] = '\0';
	return (num);
}

t_stack_node	*create_and_append_node(t_stack_node **list, char *num)
{
	t_stack_node	*new_node;
	
	if (num == NULL)
		return(NULL);
	new_node = creat_node(num);
	free(num);
	if (!new_node)
		return (NULL);
	append_list(list, new_node);
	return (new_node);
}

t_stack_node	*split(char *str)
{
	int				inx;
	t_stack_node	*list;
	char			*num;

	inx = 0;
	list = NULL;
	while (str[inx])
	{
		num = parse_number(str, &inx);
		if (!create_and_append_node(&list, num))
			return (NULL);
		while (str[inx] && str[inx] == ' ') 
			inx++;
	}
	return (list);
}
