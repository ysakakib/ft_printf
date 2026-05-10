/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:44:35 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/10 18:44:46 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int a, b;
	printf("--- Basic Tests ---\n");
	a = ft_printf("Mine: Hello %s, today is %d.\n", "42", 42);
	b = printf("Real: Hello %s, today is %d.\n", "42", 42);
	printf("Count -> Mine: %d, Real: %d\n\n", a, b);
	printf("--- Hex and Pointer Tests ---\n");
	a = ft_printf("Mine: Hex: %x, HEX: %X, Ptr: %p\n", 255, 255, &a);
	b = printf("Real: Hex: %x, HEX: %X, Ptr: %p\n", 255, 255, &a);
	printf("Count -> Mine: %d, Real: %d\n\n", a, b);
	printf("--- Null String Test ---\n");
	a = ft_printf("Mine: %s\n", NULL);
	b = printf("Real: %s\n", (char *)NULL);
	printf("Count -> Mine: %d, Real: %d\n\n", a, b);
	return (0);
}
