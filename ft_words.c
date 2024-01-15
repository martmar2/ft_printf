/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:55:37 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/15 20:56:16 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		ft_putchar(s[i]);
		i++;
	}
}
