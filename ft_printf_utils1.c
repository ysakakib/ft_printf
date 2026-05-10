/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:59:29 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 18:28:41 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putstr(const char *str, int *count)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	*count += write(1, str, len);
}

void	ft_putnbr(int nb, int *count)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		*count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	*count += ft_putchar((n % 10) + '0');
}

void	ft_putunbr(unsigned int nb, int *count)
{
	if (nb >= 10)
		ft_putunbr(nb / 10, count);
	*count += ft_putchar((nb % 10) + '0');
}

void	ft_puthex(unsigned int nb, int uppercase, int *count)
{
	char	*hex_base;

	if (uppercase)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16, uppercase, count);
	*count += ft_putchar(hex_base[nb % 16]);
}
