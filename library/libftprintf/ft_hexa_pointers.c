/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:56:14 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 12:40:54 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaconvert(unsigned long long int nbr, int uc)
{
	char	*hexadeci;
	int		i;

	i = 0;
	hexadeci = "0123456789abcdef";
	if (uc)
		hexadeci = "0123456789ABCDEF";
	if (nbr >= 16)
		i += ft_hexaconvert(nbr / 16, uc);
	i += ft_putchar(hexadeci[nbr % 16]);
	return (i);
}

int	pointers(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (ptr == 0)
		i += ft_putstr("0");
	else
		i += ft_hexaconvert(ptr, 0);
	return (i);
}
