/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:25:47 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/30 13:02:09 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	find_player_position(char **map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				player->pos_x = i;
				player->pos_y = j;
				player->direction = map[i][j];
				return ;
			}
		}
	}
}
void set_player_direction(t_player *player)
{
	
}
void	init_player(t_data *data)
{
	find_player_position(data->map.map_data, &data->player);
}
