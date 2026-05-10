/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:14:32 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 18:41:20 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_rec(unsigned long addr, int *count)
{
	if (addr >= 16)
		ft_putptr_rec(addr / 16, count);
	*count += ft_putchar("0123456789abcdef"[addr % 16]);
}

void	ft_putptr(void *ptr, int *count)
{
	if (!ptr)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	*count += write(1, "0x", 2);
	ft_putptr_rec((unsigned long)ptr, count);
}
