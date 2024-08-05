/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:45:44 by malsheri          #+#    #+#             */
/*   Updated: 2024/03/20 21:52:15 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_pointer(unsigned long ptr, char *str)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += convert_pointer(ptr / 16, str);
	len += handle_char(str[ptr % 16]);
	return (len);
}

int	handle_pointer(unsigned long ptr)
{
	int	len;

	len = 0;
	handle_string("0x");
	len += convert_pointer(ptr, "0123456789abcdef") + 2;
	return (len);
}
