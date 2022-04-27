/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:52:43 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/27 14:48:32 by dantremb         ###   ########.fr       */
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
			len += ft_choose_arg(str[i + 1], arg);
		else
		{
			write(1, (char)str[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_choose_arg(char str, va_list arg)
{
	int	len;

	len = 0;
	if (str == 'c')
		len = write(1, str, 1);
	if (str == 's')
		len = ft_putstr((va_arg(arg, char *)));
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i] != '\0')
		write(1, str[i], 1);
	return (i);
}
