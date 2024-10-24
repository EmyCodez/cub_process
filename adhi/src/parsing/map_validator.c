/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:41:48 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 13:27:42 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map_line(char *line)
{
	while (*line == ' ')
		line++;
	return (*line == '1' || *line == '0');
}

int	count_map_lines(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_printf(RED "Error\n" RESET "Failed to open file\n"), 0);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
			line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

int	read_map_lines(int fd, t_map *map)
{
	char	*line;
	int		line_count;
	int		map_start;

	line_count = 0;
	map_start = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line) && !map_start)
			map_start = 1;
		if (map_start)
		{
			map->map_data[line_count] = ft_strdup(line);
			line_count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	map->map_data[line_count] = NULL;
	return (1);
}

int	map_validator(char *path, t_map *map)
{
	int fd;

	map->map_height = count_map_lines(path);
	if (map->map_height == 0)
		return (ft_printf(RED "Error\n" RESET "No valid map lines found\n"), 0);
	map->map_data = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->map_data)
		return (ft_printf(RED "Error\n" RESET "Memory allocation failed\n"), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_printf(RED "Error\n" RESET "Failed to open file\n"), 0);
	read_map_lines(fd, map);
	close(fd);
	print_map(map);
	return (1);
}