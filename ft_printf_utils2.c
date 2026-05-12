/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:14:32 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/12 22:54:13 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_hex(unsigned long long nb, int *count)
{
	char	*base;

	if (*count == -1)
		return ;
	base = "0123456789abcdef";
	if (nb >= 16)
		ft_putptr_hex(nb / 16, count);
	if (*count == -1)
		return ;
	ft_putchar(base[nb % 16], count);
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
