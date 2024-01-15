/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:22:16 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/15 20:56:32 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printchar(char c)
{
	int	counter;

	counter = 0;
	ft_putchar(c);
	counter = counter + 1;
	return (counter);
}

int	ft_printstr(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		counter = counter + 6;
	}
	else
	{
		ft_putstr_fd(str);
		counter = counter + ft_strlen(str);
	}
	return (counter);
}
