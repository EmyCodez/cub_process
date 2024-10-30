/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:12 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/29 13:36:36 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static unsigned int	color_to_hex(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
static void	init_color(t_data *data)
{
	data->ceiling_color = color_to_hex(data->map.c_red, data->map.c_green,
			data->map.c_blue);
	data->floor_color = color_to_hex(data->map.f_red, data->map.f_green,
			data->map.f_blue);
}
static void	init_keys(t_key *key)
{
	key->a = false;
	key->d = false;
	key->w = false;
	key->s = false;
	key->left = false;
	key->right = false;
}
void	data_init(t_data *data)
{
	init_keys(&data->key);
	init_color(data);
	init_player(data);
}