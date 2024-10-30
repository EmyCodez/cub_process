/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:07:29 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 13:27:32 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	make_map_square(t_map *map)
{
	int	i;
	int	max_width;
	int	len;

	i = 0;
	max_width = 0;
	// Find the maximum width in the current map
	while (i < map->map_height)
	{
		len = strlen(map->map_data[i]);
		if (len > max_width)
		{
			max_width = len;
		}
		i++;
	}
	// Make the map square, ensuring it's as wide as the maximum width
	char **new_map = malloc(sizeof(char *) * (map->map_height + 2)); //
																		//+2 for top and bottom borders
	// Create the top border filled with '1's
	new_map[0] = malloc(max_width + 3); // +1 for '\0'
	memset(new_map[0], '1', max_width + 2);
	new_map[0][max_width + 2] = '\0';
	// Adjust the existing map, padding with '1' s to form a square
	i = 0;
	while (i < map->map_height)
	{
		new_map[i + 1] = malloc(max_width + 3);
		//+1 for '\0'
		memset(new_map[i + 1], '1', max_width + 2);
		// Initialize with '1's
		// Copy the existing map data into the new padded map
		len = strlen(map->map_data[i]);
		strncpy(new_map[i + 1] + 1, map->map_data[i], len);
		// Insert current line data,offset by 1 for padding
		new_map[i + 1][max_width + 1] = '1';
		// Right-side padding with '1'
		new_map[i + 1][max_width + 2] = '\0';
		i++;
	}
	// Create the bottom border filled with '1's
	new_map[map->map_height + 1] = malloc(max_width + 3);
	memset(new_map[map->map_height + 1], '1', max_width + 2);
	new_map[map->map_height + 1][max_width + 2] = '\0';
	// Free old map data
	i = 0;
	while (i < map->map_height)
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
	// Update the map structure
	map->map_data = new_map;
	map->map_height += 2;
	// Update the height to include the top and bottom borders
}

int	check_line_lengths(t_map *map)
{
	int	prev_len;
	int	curr_len;
	int	next_len;

	// Loop through each line,
	//starting from the second line and stopping before the last line
	int i = 1; // Start from the second line
	while (i < map->map_height - 1)
	{
		prev_len = strlen(map->map_data[i - 1]);
		curr_len = strlen(map->map_data[i]);
		next_len = strlen(map->map_data[i + 1]);
		// Check if current line is longer than both the previous and the next lines
		if (curr_len > prev_len && curr_len > next_len)
		{
			printf(RED "Error\n" RESET
						"Line	% d is longer than both the previous and next lines\n ",
					i + 1);
			return (0); // Exit the function with an error
		}
		i++; // Move to the next line
	}
	return (1); // All lines are valid
}

int	validate_map_structure(t_map *map)
{
	if (!check_line_lengths(map))
	{
		ft_printf(RED
					"Error\n" RESET
					"Map has invalid structure due to line length inconsistency.\n");
		return (0);
	}
	ft_printf("Map structure is valid.\n");
	return (1);
}

int	check_valid_characters(t_map *map)
{
	int		i;
	int		j;
	char	*allowed_chars;

	i = 0;
	allowed_chars = "01 NSEW";
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (!ft_strchr(allowed_chars, map->map_data[i][j]))
				return (ft_printf(RED "Error\n" RESET "Invalid character '%c' in map\n",
									map->map_data[i][j]),
						0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player_position(t_map *map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (ft_strchr("NSEW", map->map_data[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (printf(RED "Error\n" RESET
							"There should be exactly 1 player start position,	found	%d\n",
						player_count),
				0);
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	// Check top and bottom rows (should only contain '1' and spaces)
	while (map->map_data[0][i] && map->map_data[map->map_height - 1][i])
	{
		if (map->map_data[0][i] != '1' && map->map_data[0][i] != ' ')
			return (ft_printf(RED "Error\n" RESET
									"Top boundary is not closed by walls\n"),
					0);
		if (map->map_data[map->map_height - 1][i] != '1' &&
			map->map_data[map->map_height - 1][i] != ' ')
			return (ft_printf(RED "Error\n" RESET
									"Bottom boundary is not closed by walls\n"),
					0);
		i++;
	}
	// Check left and right sides
	i = 0;
	while (map->map_data[i])
	{
		if (map->map_data[i][0] != '1' && map->map_data[i][0] != ' ')
			return (ft_printf(RED "Error\n" RESET
									"Left boundary is not closed by walls\n"),
					0);
		j = ft_strlen(map->map_data[i]) - 1;
		if (map->map_data[i][j] != '1' && map->map_data[i][j] != ' ')
			return (ft_printf(RED "Error\n" RESET
									"Right boundary is not closed by walls\n"),
					0);
		i++;
	}
	return (1);
}

int	map_checks(t_map *map)
{
	if (!check_valid_characters(map))
		return (0);
	ft_printf(GREEN "Character check Successfull\n" RESET);
	if (!check_player_position(map))
		return (0);
	ft_printf(GREEN "Player Position Check Successfull\n" RESET);
	if (!check_walls(map))
		return (0);
	make_map_square(map);

	if (!validate_map_structure(map))
		return (0);
	if (!validate_and_replace_spaces(map))
		return (0);
	ft_printf(GREEN "Map Wall Check Successfull\n" RESET);
	return (1);
}