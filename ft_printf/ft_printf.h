/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsheri <malsheri@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:45:30 by malsheri          #+#    #+#             */
/*   Updated: 2024/03/21 19:30:55 by malsheri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	handle_char(int c);
int	handle_hexa(unsigned int num, char x);
int	handle_num(int num);
int	handle_pointer(unsigned long ptr);
int	handle_string(const char *string);
int	handle_unum(unsigned int unum);

#endif