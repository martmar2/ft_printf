/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:56:29 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/15 20:49:52 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == (-2147483648))
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	num = n % 10 + '0';
	write(fd, &num, 1);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	num;

	if (n > 9)
		ft_putnbr_unsigned_fd(n / 10, fd);
	num = n % 10 + '0';
	write(fd, &num, 1);
}

void	ft_caphexad(unsigned long n)
{
	if (n < 10)
		ft_putchar(n + '0');
	if (n == 10)
		ft_putchar('A');
	if (n == 11)
		ft_putchar('B');
	if (n == 12)
		ft_putchar('C');
	if (n == 13)
		ft_putchar('D');
	if (n == 14)
		ft_putchar('E');
	if (n == 15)
		ft_putchar('F');
	if (n > 15)
	{
		ft_caphexad(n / 16);
		ft_caphexad(n % 16);
	}
}

void	ft_lowhexad(unsigned long n)
{
	if (n < 10)
		ft_putchar(n + '0');
	if (n == 10)
		ft_putchar('a');
	if (n == 11)
		ft_putchar('b');
	if (n == 12)
		ft_putchar('c');
	if (n == 13)
		ft_putchar('d');
	if (n == 14)
		ft_putchar('e');
	if (n == 15)
		ft_putchar('f');
	if (n > 15)
	{
		ft_lowhexad(n / 16);
		ft_lowhexad(n % 16);
	}
}
