/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:15:49 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/12 16:08:33 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_unsigned(va_list *args, int *count)
{
	ft_putunbr(va_arg(*args, unsigned int), count);
}

void	handle_hex_lower(va_list *args, int *count)
{
	ft_puthex(va_arg(*args, unsigned int), 0, count);
}

void	handle_hex_upper(va_list *args, int *count)
{
	ft_puthex(va_arg(*args, unsigned long long int), 1, count);
}

void	handle_percent(int *count)
{
	ft_putchar('%', count);
}
