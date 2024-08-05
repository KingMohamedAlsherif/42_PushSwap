/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:45:37 by malsheri          #+#    #+#             */
/*   Updated: 2024/03/21 20:00:19 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hexa(unsigned int num, char x)
{
	char	*hexa;
	int		len;

	len = 0;
	if (x == 'x')
		hexa = "0123456789abcdef";
	if (x == 'X')
		hexa = "0123456789ABCDEF";
	if (num > 15)
		len += handle_hexa(num / 16, x);
	handle_char(hexa[num % 16]);
	len++;
	return (len);
}
