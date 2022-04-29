/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:05:00 by root              #+#    #+#             */
/*   Updated: 2022/04/29 13:29:37 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		len;
	//int		i;
	int		*p;

	//i = 1;
	p = NULL;
	printf("\n\033[0;32mMY FUNCTION\033[0;37m\n");
	len = ft_printf(" %p %p ", p, p);	printf("\033[0;32m = %d writed\033[0;37m\n", len);
	printf("\n\033[0;32m----------------------------\033[0;37m\n");
	printf("\n\033[0;32mTRUE FUNCTION\033[0;37m\n");
	len = printf(" %p %p ", p, p);
	printf("\033[0;32m = %d writed\033[0;37m", len);
	return (0);
}
