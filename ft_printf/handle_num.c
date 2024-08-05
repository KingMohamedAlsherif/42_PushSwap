/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:45:40 by malsheri          #+#    #+#             */
/*   Updated: 2024/03/20 21:47:46 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_num(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (num < 0)
	{
		len += handle_char('-');
		len += handle_num((num * -1));
	}
	else
	{
		if (num >= 10)
			len += handle_num(num / 10);
		len += handle_char(num % 10 + 48);
	}
	return (len);
}
