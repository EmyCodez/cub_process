/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:08:07 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:45 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 720
# define WIN_HEIGHT 560
# define ROTATE_SPEED 0.05
# define MOVE_SPEED 0.05

/* ------------------------------- INCLUDES --------------------------------- */

# include "../library/get_next_line/get_next_line.h"
# include "../library/libft/libft.h"
# include "../library/libftprintf/ft_printf.h"
# include "../library/mlx/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

# define COLOUR_EXCEED_VALUE 255

/* ----------------------------- DATA STRUCTURES --------------------------- */

typedef struct s_map
{
	char		**map_data;
	char		**map_data_cpy;
	int			map_height;
	int			map_width;
	int			player_cnt;
	int			f_red;
	int			f_green;
	int			f_blue;
	int			c_red;
	int			c_green;
	int			c_blue;
	char		*no_texture_path;
	char		*so_texture_path;
	char		*ea_texture_path;
	char		*we_texture_path;
	char		**hold_color_value;
	char		*ceiling_color_value;
	char		*floor_color_value;
}				t_map;

typedef struct s_image
{
	void		*img;
	char		*address;
	int			bits_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_key
{
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		left;
	bool		right;
}				t_key;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		direction;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_key		key;
	t_player	player;
	t_image		cur_img;
	t_image		north_texture;
	t_image		south_texture;
	t_image		west_texture;
	t_image		east_texture;
	int			floor_color;
	int			ceiling_color;
}				t_data;

/* --------------------------- FUNCTION PROTOTYPES ------------------------- */

/* ************************************************************************** */
/*                              FILENAME: parse.c                             */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

void			parse_input(char *path, t_map *map);

/* ************************************************************************** */
/*                              FILENAME: struct_init.c                       */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

void			struct_initialization(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: extention_check.c                   */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

int				validate_file_extention(char *str);

/* ************************************************************************** */
/*                              FILENAME: texture_validator.c                 */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

int				validate_texture(char *path, t_map *map);
int				check_texture_identifiers_is_present(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: color_validator.c                   */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

int				validate_color(char *path, t_map *map);

/* ************************************************************************** */
/*                              FILENAME: map_validator.c                     */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

int				map_validator(char *path, t_map *map);

/* ************************************************************************** */
/*                              FILENAME: map_checks                          */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

int				map_checks(t_map *map);

int				validate_and_replace_spaces(t_map *map);

void			print_map(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: init_data.c                         */
/* ************************************************************************** */
void			data_init(t_data *data);

/* ************************************************************************** */
/*                              FILENAME: init_player.c                       */
/* ************************************************************************** */
void			init_player(t_data *data);

/* ************************************************************************** */
/*                              FILENAME: execute.c                           */
/* ************************************************************************** */

void			execute(t_data *data);

#endif
