/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:40 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/29 13:55:05 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC "0123456789"
# define HEXU "0123456789ABCDEF"
# define HEXL "0123456789abcdef"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_choose_arg(char str, va_list arg);
int		ft_put_str(char *str);
int		ft_put_char(char src);
int		ft_put_nbr(int nbr);
int		ft_len(unsigned long nbr, int base);
int		ft_put_hex(unsigned long int nbr, unsigned int base, char *hex);
int		ft_put_ptr(unsigned long int nbr);

#endif