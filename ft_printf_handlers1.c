/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:59:17 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 18:48:17 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list *args, int *count)
{
	*count += ft_putchar(va_arg(*args, int));
}

void	handle_string(va_list *args, int *count)
{
	ft_putstr(va_arg(*args, char *), count);
}

void	handle_pointer(va_list *args, int *count)
{
	ft_putptr(va_arg(*args, void *), count);
}

void	handle_decimal(va_list *args, int *count)
{
	ft_putnbr(va_arg(*args, int), count);
}

void	handle_integer(va_list *args, int *count)
{
	ft_putnbr(va_arg(*args, int), count);
}
