/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:40 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/28 13:23:41 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_choose_arg(char str, va_list arg);

int		ft_put_str(char *str);
int		ft_put_char(char src);

int		ft_put_nbr(int nbr);
int		ft_put_u_nbr(unsigned int nbr);
int		ft_intlen(long long int nbr);

#endif