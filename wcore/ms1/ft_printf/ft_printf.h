/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:03:31 by htoe              #+#    #+#             */
/*   Updated: 2025/12/12 06:59:59 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//main function
int		ft_printf(const char *str, ...);
void	flag_check(va_list args, char c);

//counting output byte
int		ft_count(int flag);

//printing function
void	ft_printf_putchar(char c);
void	ft_printf_putstr(char *str);
void	ft_printf_pointer(void *ptr);
void	ft_printf_putnbr(int nbr, int flag);
void	ft_printf_puthex(unsigned int nbr, int flag);

#endif