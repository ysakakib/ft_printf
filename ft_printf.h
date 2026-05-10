/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:45:58 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 21:42:25 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(char c, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putunbr(unsigned int nb, int *count);
void	ft_puthex(unsigned int nb, int uppercase, int *count);
void	ft_putptr(void *ptr, int *count);

void	handle_char(va_list *args, int *count);
void	handle_string(va_list *args, int *count);
void	handle_pointer(va_list *args, int *count);
void	handle_decimal(va_list *args, int *count);
void	handle_integer(va_list *args, int *count);
void	handle_unsigned(va_list *args, int *count);
void	handle_hex_lower(va_list *args, int *count);
void	handle_hex_upper(va_list *args, int *count);
void	handle_percent(int *count);

#endif
