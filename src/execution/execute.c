/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:05:38 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/29 13:08:47 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	execute(t_data *data)
{
	data_init(data);
	printf("\n Ceiling Color= %x", data->ceiling_color);
	printf("\n Floor Color= %x", data->floor_color);
}
