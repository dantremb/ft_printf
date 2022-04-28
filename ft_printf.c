/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:43 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/28 16:36:06 by dantremb         ###   ########.fr       */
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
		{
			len += ft_choose_arg(str[i++ + 1], arg);
		}
		else
		{
			len += ft_put_char(str[i]);
		}
		i++;
	}
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
	else if (str == 'u')
		len = ft_put_u_nbr(va_arg(arg, unsigned int));
	else if (str == 'p')
		len = ft_put_ptr(va_arg(arg, unsigned long ), 1);
	else if (str == 'x')
		len = ft_put_hex(va_arg(arg, unsigned int), 16, "0123456789abcdef");
	else if (str == 'X')
		len = ft_put_hex(va_arg(arg, unsigned int), 16, "0123456789ABCDEF");
	return (len);
}

int	ft_put_str(char *str)
{
	int	i;

	if (!str)
	{
		ft_put_str("(null)");
		return (6);
	}
	i = -1;
	while (str[++i] != '\0')
		ft_put_char(str[i]);
	return (i);
}

int	ft_put_char(char src)
{
	write(1, &src, 1);
	return (1);
}
