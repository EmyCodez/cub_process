/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:15:14 by esimpson          #+#    #+#             */
/*   Updated: 2024/09/23 13:34:29 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	return ((int)write(fd, &c, 1));
}


// int	main(void)
// {
// 	ft_putchar_fd(65,1);
// 	return (0);
// }
