/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:51:55 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/15 20:51:26 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_main_step(va_list args, const char *format, int i)
{
	int	counter;

	counter = 0;
	if (format[i] == 'c')
		counter += ft_printchar(va_arg(args, int));
	if (format[i] == 's')
		counter += ft_printstr(va_arg(args, char *));
	if (format[i] == '%')
		counter += ft_printchar('%');
	if (format[i] == 'i' || format[i] == 'd')
		counter += ft_print_number(va_arg(args, int));
	if (format[i] == 'u')
		counter += ft_unsigned(va_arg(args, unsigned int));
	if (format[i] == 'x')
		counter += ft_print_lowhexa(va_arg(args, unsigned int));
	if (format[i] == 'X')
		counter += ft_print_caphexa(va_arg(args, unsigned int));
	if (format[i] == 'p')
		counter += ft_print_pointer(va_arg(args, unsigned long));
	return (counter);
}

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
			counter = counter + ft_main_step(args, format, i);
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
