/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:24 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/13 18:57:48 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

void		ft_putchar(char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(const char *s);
int			ft_unsignedintlen(unsigned int a);
void		ft_caphexad(unsigned long n);
void		ft_lowhexad(unsigned long n);
int			ft_printf(const char *format, ...);
int			ft_counter(const char *format, ...);
int 		ft_hexadlen(unsigned long n);
int			ft_intlen(int a);
void		ft_putnbr_unsigned_fd(unsigned int n, int fd);

#endif
