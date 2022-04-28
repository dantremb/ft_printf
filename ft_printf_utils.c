/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:19:53 by dantremb          #+#    #+#             */
/*   Updated: 2022/04/28 13:24:34 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (ft_intlen(nbr));
}

int	ft_put_u_nbr(unsigned int nbr)
{
	if (nbr > 9)
		ft_put_u_nbr(nbr / 10);
	ft_put_char('0' + nbr % 10);
	return (ft_intlen(nbr));
}

int	ft_intlen(long long int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
