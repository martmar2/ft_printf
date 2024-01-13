/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:48:02 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/13 18:57:11 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	int count;

	count = 1;
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	(void) fd;
	// quitar el parametro fd
	i = 0;
	while (s[i] != 0)
	{
		ft_putchar(s[i]);
		i++;
	}
}

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

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

int	ft_intlen(int a)
{
	int	count;

	count = 0;
	if (a == INT_MIN)
		return (11);
	if (a < 0)
	{
		count++;
		a = -a;
	}
	while (a > 9)
	{
		a = (a / 10);
		count++;
	}
	return (count + 1);
}

int	ft_unsignedintlen(unsigned int a)
{
	int	count;

	count = 0;
	while (a > 9)
	{
		a = (a / 10);
		count++;
	}
	return (count + 1);
}

void ft_caphexad(unsigned long n)
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

void ft_lowhexad(unsigned long n)
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

int ft_hexadlen(unsigned long n)
{
    int count = 0;

    while (n > 0)
    {
        count++;
        n = n / 16;
    }

    if (count == 0)
		return (1);
	return (count);
}
