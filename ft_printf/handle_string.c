/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:45:47 by malsheri          #+#    #+#             */
/*   Updated: 2024/03/20 21:35:35 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(const char *string)
{
	int	i;

	i = 0;
	if (!string)
	{
		return (write(1, "(null)", 6));
		return (6);
	}
	while (string[i] != '\0')
	{
		handle_char(string[i]);
		i++;
	}
	return (i);
}
