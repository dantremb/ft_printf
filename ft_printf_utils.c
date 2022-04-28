/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:19:53 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/28 16:47:57 by dantremb         ###   ########.fr       */
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
	printf("\nft_len = %ld\n");
	return (len);
}

int	ft_put_ptr(unsigned long ptr, int base)
{
	if (base == 1)
	{
		ft_put_str("0x");
		if (ptr == 0)
		{
			ft_put_char('0');
			return (3);
		}
	}
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16, 0);
		ft_put_ptr(ptr % 16, 0);
	}
	else
		ft_put_char("0123456789abcdef"[ptr % 16]);
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
	if (nbr != -2147483648)
	{
		if (nbr < 0)
		{
			ft_put_char('-');
			ft_put_nbr(-nbr);
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
	return (ft_len(nbr, 10));
}

int	ft_put_u_nbr(unsigned int nbr)
{
	if (nbr > 9)
		ft_put_u_nbr(nbr / 10);
	ft_put_char('0' + nbr % 10);
	return (ft_len(nbr, 10));
}
