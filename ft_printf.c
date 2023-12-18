/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:51:55 by martmar2          #+#    #+#             */
/*   Updated: 2023/12/18 19:15:21 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
#include <stdarg.h>

void checker(char type, va_list args)
{
}

int	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			write(1, &format[i], 1);
			char tipo = format[i];
		}
		else
			write (1, &format[i], 1);
	     	i++;
			i = i + 1;
	}
	return (0);
}

char* str = va_arg(args, char*)

int main(void)
{
	//printf("hola %s %s \n ", "haha", 'a');
	ft_printf("hola %s mundo %d que %x tal");
}
