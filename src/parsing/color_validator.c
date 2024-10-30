/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:56:37 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 13:27:09 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	assign_the_ceiling_color(t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	**hold_color_value;

	i = 0;
	j = 0;
	k = 0;
	hold_color_value = ft_split(map->ceiling_color_value, ',');
	while (hold_color_value[i])
	{
		j = 0;
		while (hold_color_value[i][j])
		{
			if (ft_isdigit(hold_color_value[i][j]))
			{
				if (ft_atoi(hold_color_value[i]) > COLOUR_EXCEED_VALUE)
					return (ft_printf(RED "Error\n" RESET "Color value exceeds 255\n"),
							0);
				if (k == 0)
				{
					map->c_red = ft_atoi(hold_color_value[i]);
					ft_printf("c_red-> %d\n", map->c_red);
				}
				if (k == 1)
				{
					map->c_green = ft_atoi(hold_color_value[i]);
					ft_printf("c_green-> %d\n", map->c_green);
				}
				if (k == 2)
				{
					map->c_blue = ft_atoi(hold_color_value[i]);
					ft_printf("c_blue-> %d\n", map->c_blue);
				}
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	assign_the_floor_color(t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	**hold_color_value;

	i = 0;
	j = 0;
	k = 0;
	hold_color_value = ft_split(map->floor_color_value, ',');
	while (hold_color_value[i])
	{
		j = 0;
		while (hold_color_value[i][j])
		{
			if (ft_isdigit(hold_color_value[i][j]))
			{
				if (ft_atoi(hold_color_value[i]) > COLOUR_EXCEED_VALUE)
					return (ft_printf(RED "Error\n" RESET "Color value exceeds 255\n"),
							0);
				if (k == 0)
				{
					map->f_red = ft_atoi(hold_color_value[i]);
					ft_printf("f_red-> %d\n", map->f_red);
				}
				if (k == 1)
				{
					map->f_green = ft_atoi(hold_color_value[i]);
					ft_printf("f_green-> %d\n", map->f_green);
				}
				if (k == 2)
				{
					map->f_blue = ft_atoi(hold_color_value[i]);
					ft_printf("f_blue-> %d\n", map->f_blue);
				}
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_color(char *path, t_map *map)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf(RED "Error\n" RESET "Failed to open file\n"), 0);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
		{
			map->floor_color_value = ft_strdup(line + 2);
			ft_printf("F-> %s\n", map->floor_color_value);
		}
		if (ft_strncmp(line, "C ", 2) == 0)
		{
			map->ceiling_color_value = ft_strdup(line + 2);
			ft_printf("C-> %s\n", map->ceiling_color_value);
		}
		line = get_next_line(fd);
	}
	ft_printf("\n");
	assign_the_floor_color(map);
	ft_printf("\nFloor color assigned\n");
	assign_the_ceiling_color(map);
	ft_printf("\nCeiling color assigned\n");
	return (1);
}