/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:51:55 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/10 18:59:40 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
#include <stdarg.h>

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
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar(va_arg(args, int));
			if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char*), 1);
			if (format[i] == '%')
				write(1, "%", 1);
			if (format[i] == 'i' || format[i] == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (format[i] == 'u')
				ft_putnbr_fd(va_arg(args, unsigned int));
			if (format[i] == 'x')
				ft_lowhexad(va_arg(args, unsigned long));
			if (format[i] == 'X')
				ft_caphexad(va_arg(args, unsigned long));
			//count = ft_counter
			i++;
		}	
		else
		{
			write (1, &format[i], 1);
	     	i++;
		}
	}
	return (0);
}

int main(void)
{
	//ft_printf("hola %s %s \n ", "haha", "a");
	ft_printf("hola %s mundo %d que %x tal\n", "hakim guapo", 105, 112);
	ft_printf("%d\n", 12543);
	ft_printf("%d%d%d%s%s%i%d%x%X%%%%%X\n", 69,420,88008,"ewe","sasuaje putero",666,42,15,456,7879);

}
