/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:40 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/29 22:58:40 by dantremb         ###   ########.fr       */
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
void	ft_choose_arg(char str, va_list arg, int *p);
void	ft_put_str(char *str, int *p);
void	ft_put_char(char src, int *p);
void	ft_put_nbr(int nbr, int *p);
void	ft_put_hex(unsigned long int nbr, unsigned int base, char *hex, int *p);
void	ft_put_ptr(unsigned long int nbr, int *p);

#endif