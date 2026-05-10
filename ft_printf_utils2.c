/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:14:32 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 21:55:18 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nb, int uppercase, int *count)
{
	char	*hex_base;

	if (*count == -1)
		return ;
	if (uppercase)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16, uppercase, count);
	if (*count == -1)
		return ;
	ft_putchar(hex_base[nb % 16], count);
}

void	ft_puthex(unsigned int nb, int uppercase, int *count)
{
	char	*hex_base;

	if (*count == -1)
		return ;
	if (uppercase)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16, uppercase, count);
	if (*count == -1)
		return ;
	ft_putchar(hex_base[nb % 16], count);
}
