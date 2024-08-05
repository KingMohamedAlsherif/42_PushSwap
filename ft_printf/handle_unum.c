/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:45:50 by malsheri          #+#    #+#             */
/*   Updated: 2024/03/20 21:35:46 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_unum(unsigned int unum)
{
	int	len;

	len = 0;
	if (unum >= 10)
		len += handle_unum(unum / 10);
	len += handle_char(unum % 10 + 48);
	return (len);
}
