/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:59:40 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 21:56:48 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_conversion(const char *format, int *i, va_list *args,
		int *count)
{
	(*i)++;
	if (format[*i] == 'c')
		return (handle_char(args, count));
	else if (format[*i] == 's')
		return (handle_string(args, count));
	else if (format[*i] == 'p')
		return (handle_pointer(args, count));
	else if (format[*i] == 'd' || format[*i] == 'i')
		return (handle_decimal(args, count));
	else if (format[*i] == 'u')
		return (handle_unsigned(args, count));
	else if (format[*i] == 'x')
		return (handle_hex_lower(args, count));
	else if (format[*i] == 'X')
		return (handle_hex_upper(args, count));
	else if (format[*i] == '%')
		return (handle_percent(count));
	else
	{
		*count += ft_putchar('%', count);
		(*i)--;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			process_conversion(format, &i, &args, &count);
		}
		else
		{
			ft_putchar(format[i], &count);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
