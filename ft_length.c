/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:44:34 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/15 20:55:04 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

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

int	ft_hexadlen(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	if (count == 0)
		return (1);
	return (count);
}
