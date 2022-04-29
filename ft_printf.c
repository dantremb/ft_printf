/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:43 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/29 13:56:17 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_choose_arg(str[i++ + 1], arg);
		else
			len += ft_put_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

int	ft_choose_arg(char str, va_list arg)
{
	int	len;

	len = 0;
	if (str == 's')
		len = ft_put_str(va_arg(arg, char *));
	else if (str == 'c')
		len = ft_put_char(va_arg(arg, int));
	else if (str == '%')
		len = ft_put_char(str);
	else if (str == 'd' || str == 'i')
		len = ft_put_nbr(va_arg(arg, int));
	else if (str == 'p')
		len = ft_put_ptr(va_arg(arg, unsigned long ));
	else if (str == 'u')
		len = ft_put_hex(va_arg(arg, unsigned int), 10, DEC);
	else if (str == 'x')
		len = ft_put_hex(va_arg(arg, unsigned int), 16, HEXL);
	else if (str == 'X')
		len = ft_put_hex(va_arg(arg, unsigned int), 16, HEXU);
	return (len);
}

int	ft_put_char(char src)
{
	write(1, &src, 1);
	return (1);
}
