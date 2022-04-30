/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:05:00 by root              #+#    #+#             */
/*   Updated: 2022/04/29 23:04:31 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		len;

	printf("\n\033[0;36mMY FUNCTION\033[0;37m\n");
	len = ft_printf("salut!");
	printf("\033[0;32m = %d writed\033[0;37m\n", len);
	printf("\033[0;36mTRUE FUNCTION\033[0;37m\n");
	len = printf("salut!");
	printf("\033[0;32m = %d writed\033[0;37m", len);
	return (0);
}
