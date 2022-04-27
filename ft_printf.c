/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:43 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/17 13:49:12 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;

	va_start(arg, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_print_arg(str, arg);
		else
			printf("%c", str[i]);
		i++;
	}
	return (i);
}

size_t	ft_print_arg(char *str, va_list arg)
{
	size_t	len;

	len = printf("%s", va_arg(arg, char *));
	return (len);
}
