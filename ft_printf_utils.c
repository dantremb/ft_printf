/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:19:53 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/28 18:14:23 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned long nbr, int base)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int	ft_put_ptr(unsigned long ptr)
{
	ft_put_str("0x");
	if (ptr == 0)
	{
		ft_put_char('0');
		return (3);
	}
	ft_put_hex(ptr, 16, "0123456789abcdef");
	return (ft_len(ptr, 16) + 2);
}

int	ft_put_hex(unsigned long nbr, unsigned int base, char *hex)
{
	if (nbr >= base)
	{
		ft_put_hex(nbr / base, base, hex);
		ft_put_hex(nbr % base, base, hex);
	}
	else
		ft_put_char(hex[nbr % base]);
	return (ft_len(nbr, base));
}

int	ft_put_nbr(int nbr)
{
	int	len;

	len = ft_len(nbr, 10);
	if (nbr != -2147483648)
	{
		if (nbr < 0)
		{
			len = ft_len(nbr * -1, 10);
			ft_put_char('-');
			ft_put_nbr(-nbr);
			len++;
		}
		else
		{
			if (nbr > 9)
				ft_put_nbr(nbr / 10);
			ft_put_char('0' + nbr % 10);
		}
	}
	else
	{
		ft_put_str("-2147483648");
		return (11);
	}
	return (len);
}

int	ft_put_u_nbr(unsigned int nbr)
{
	if (nbr > 9)
		ft_put_u_nbr(nbr / 10);
	ft_put_char('0' + nbr % 10);
	return (ft_len(nbr, 10));
}
