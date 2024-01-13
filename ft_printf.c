/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:51:55 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/13 21:32:44 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

//int	ft_counter(const char *format, ...)
//{
//	int		i;
//	va_list	args;
//	int		count;
//
//	i = 0;
//	count = 0;
//	va_start(args, format);
//	while (format[i])
//	{
//		if (format[i] == 'c' || format[i] == '%')
//			count = count + 1;
//		if (format[i] == 's' || format[i] == 'x' || format[i] == 'X')
//			count = count + ft_strlen(va_arg(args, char*), 1);
//		if (format[i] == 'i' || format[i] == 'd')
//			count = count + ft_intlen(va_arg(args, int), 1);
//		if (format[i] == 'u')
//			count = count + ft_unsignedintlen(va_arg(args, unsigned int), 1);
//	return (count);
//	}
//}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				ft_putchar(va_arg(args, int));
				counter = counter + 1;
			}
			if (format[i] == 's')
			{
				char *str = va_arg(args, char*);
				if (str == NULL)
				{
					write(1, "(null)", 6);
			   		counter = counter + 6;
				}	
				else
				{
					ft_putstr_fd(str, 1);
					counter = counter + ft_strlen(str);
				}
			}
			if (format[i] == '%')
			{
				write(1, "%", 1);
				counter = counter + 1;
			}
			if (format[i] == 'i' || format[i] == 'd')
			{
				int	n = va_arg(args, int);
				ft_putnbr_fd(n, 1);
				counter = counter + ft_intlen(n);
			}
			if (format[i] == 'u')
			{
				unsigned int n = va_arg(args, unsigned int);
				ft_putnbr_unsigned_fd(n, 1);
				counter = counter + ft_unsignedintlen(n);
			}
			if (format[i] == 'x')
			{
				unsigned int	n = va_arg(args, unsigned int);
				ft_lowhexad(n);
				counter = counter + ft_hexadlen(n);
			}
			if (format[i] == 'X')
			{
				unsigned int n = va_arg(args, unsigned int);
				ft_caphexad(n);
				counter = counter + ft_hexadlen(n);
			}
			if (format[i] == 'p')
			{
				write (1, "0x", 2);
				unsigned long n = va_arg(args, unsigned long);
				ft_lowhexad(n);
				counter = counter + ft_hexadlen(n) + 2;
			}
			i++;
		}	
		else
		{
			write (1, &format[i], 1);
			counter = counter + 1;
	     	i++;
		}
	}
	return (counter);
}

//int main(void)
//{
//	ft_printf("%X\n", LONG_MIN);
//	printf("%X\n", LONG_MIN);
//}
