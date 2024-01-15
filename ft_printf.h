/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:24 by martmar2          #+#    #+#             */
/*   Updated: 2024/01/15 20:55:44 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void		ft_putchar(char c);
void		ft_putstr_fd(char *s);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(const char *s);
int			ft_unsignedintlen(unsigned int a);
void		ft_caphexad(unsigned long n);
void		ft_lowhexad(unsigned long n);
int			ft_printf(const char *format, ...);
int			ft_counter(const char *format, ...);
int			ft_hexadlen(unsigned long n);
int			ft_intlen(int a);
void		ft_putnbr_unsigned_fd(unsigned int n, int fd);
int			ft_print_number(int n);
int			ft_unsigned(unsigned int n);
int			ft_print_lowhexa(unsigned int n);
int			ft_print_caphexa(unsigned int n);
int			ft_print_pointer(unsigned long n);
int			ft_printchar(char c);
int			ft_printstr(char *str);

#endif
