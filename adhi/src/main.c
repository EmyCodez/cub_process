/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:10:52 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/24 15:29:19 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf(RED "(ERROR) Input 2 arguments\n" RESET);
		exit(EXIT_FAILURE);
	}
	parse_input(av[1], &data.map);
	return (0);
}
