/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:59:29 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 23:50:11 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*count = -1;
	else
		*count += 1;
}

void	ft_putstr(const char *str, int *count)
{
	int	len;
	int	res;

	if (*count == -1)
		return ;
	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	res = write(1, str, len);
	if (res == -1)
		*count = -1;
	else
		*count += res;
}

void	ft_putnbr(int nb, int *count)
{
	long	n;

	if (*count == -1)
		return ;
	n = nb;
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (*count == -1)
		return ;
	if (n >= 10)
		ft_putnbr(n / 10, count);
	if (*count == -1)
		return ;
	ft_putchar((n % 10) + '0', count);
}

void	ft_putunbr(unsigned int nb, int *count)
{
	if (*count == -1)
		return ;
	if (nb >= 10)
		ft_putunbr(nb / 10, count);
	if (*count == -1)
		return ;
	ft_putchar((nb % 10) + '0', count);
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
