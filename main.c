/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:05:00 by root              #+#    #+#             */
/*   Updated: 2022/04/27 14:44:17 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("salut toi sa %s? ", "va");
	printf(" = %i writed", len);
	ft_printf("\n");
	return (0);
}
