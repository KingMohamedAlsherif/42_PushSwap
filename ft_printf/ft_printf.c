/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:45:21 by malsheri          #+#    #+#             */
/*   Updated: 2024/03/21 20:00:01 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_format(va_list args, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += handle_char(va_arg(args, int));
	else if (type == 's')
		len += handle_string(va_arg(args, char *));
	else if (type == 'u')
		len += handle_unum(va_arg(args, unsigned int));
	else if (type == 'i' || type == 'd')
		len += handle_num(va_arg(args, int));
	else if (type == 'x' || type == 'X')
		len += handle_hexa(va_arg(args, int), type);
	else if (type == 'p')
		len += handle_pointer(va_arg(args, unsigned long));
	else if (type == '%')
		len += handle_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += convert_format(args, str[++i]);
		else
			len += handle_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
