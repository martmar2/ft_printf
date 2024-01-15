/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:06:23 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/15 20:46:51 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_print_number(int n)
{
	int	counter;

	counter = 0;
	ft_putnbr_fd(n, 1);
	counter = counter + ft_intlen(n);
	return (counter);
}

int	ft_unsigned(unsigned int n)
{
	int	counter;

	counter = 0;
	ft_putnbr_unsigned_fd(n, 1);
	counter = counter + ft_unsignedintlen(n);
	return (counter);
}

int	ft_print_lowhexa(unsigned int n)
{
	int	counter;

	counter = 0;
	ft_lowhexad(n);
	counter = counter + ft_hexadlen(n);
	return (counter);
}

int	ft_print_caphexa(unsigned int n)
{
	int	counter;

	counter = 0;
	ft_caphexad(n);
	counter = counter + ft_hexadlen(n);
	return (counter);
}

int	ft_print_pointer(unsigned long n)
{
	int	counter;

	counter = 0;
	write(1, "0x", 2);
	ft_lowhexad(n);
	counter = counter + ft_hexadlen(n) + 2;
	return (counter);
}
