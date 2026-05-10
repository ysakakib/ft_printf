/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:14:32 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/11 00:25:57 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_hex(unsigned long long n, int *count)
{
	char	*hex_base;

	if (*count == -1)
		return ;
	hex_base = "0123456789abcdef";
	if (n >= 16)
		ft_putptr_hex(n / 16, count);
	if (*count == -1)
		return ;
	ft_putchar(hex_base[n % 16], count);
}

void	ft_putptr(void *ptr, int *count)
{
	unsigned long long	addr;

	if (*count == -1)
		return ;
	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	addr = (unsigned long long)ptr;
	ft_putstr("0x", count);
	ft_putptr_hex(addr, count);
}
