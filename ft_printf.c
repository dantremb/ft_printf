/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:43 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/28 00:51:22 by dantremb         ###   ########.fr       */
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
		//printf("\nPRINT LOOP str[%i]=%c", len, str[i]);
		if (str[i] == '%')
		{
			len += ft_choose_arg(str[i + 1], arg);
			i++;
			//printf("\n LOOP modulo str[%i]=%c", len, str[i]);
		}
		else
		{
			len += ft_putchar(str[i]);
			//printf("\n LOOP char str[%i]=%c", len, str[i]);
		}
		i++;
	}
	return (len);
}

int	ft_choose_arg(char str, va_list arg)
{
	int	len;

	len = 0;
	if (str == 'c' || str == 's')
		len = ft_putstr(va_arg(arg, char *));
	else if (str == '%')
		len = ft_putchar(str);
	else if (str == 'd' || str == 'i' || str == 'u')
		len = ft_putnbr(va_arg(arg, int));
	/*else if (str == 'p')
		len = printf("Pointer en HEX");
	else if (str == 'X' || str == 'x')
		len = printf("nombre en base HEX");*/
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i] != '\0')
		putchar(str[i]);
	return (i);
}

int	ft_putchar(char src)
{
	write(1, &src, 1);
	return (1);
}
