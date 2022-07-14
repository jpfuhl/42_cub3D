/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:42:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 17:11:24 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080
# define TEXTURE_SIZE	128
# define PI				3.141592

enum e_texture_type
{
	DEFAULT = -1,
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING
};

/*	POINT OR VECTOR */
typedef struct s_xy
{
	double	x;
	double	y;
}	t_xy;

// change this
typedef struct s_ray
{
	t_xy	vector;
	t_xy	dir;
	int		c_mapx;
	int		c_mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltax;
	double	deltay;
	int		stepx;
	int		stepy;
	int		axis;
	int		colour;
	int		wall;
	double	perp_wall_distance;
	double	line_position;
	int		line_height;
	double	line_height_start;
	double	line_step;
	int		draw_start;
	int		draw_end;
	t_xy	intersection;
}	t_ray;

// CAMERA ?

/*	PLAYER */
typedef struct s_player
{
	int		i;
	int		j;
	double	x;
	double	y;
	int		rotation;
}	t_player;

/*	IMAGE */
typedef struct s_image
{
	void	*pointer;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

/*	WINDOW */
typedef struct s_window
{
	void	*pointer;
	int		width;
	int		height;
	t_image	*screen;
	t_image	*map;
	t_image	*minimap;
}	t_window;

typedef struct s_element
{
	bool	set;
	t_image	*texture;
	int		r;
	int		g;
	int		b;
	int		colour;
}	t_element;

typedef struct s_tile
{
	char	id;
	int		i;
	int		j;
	double	x_o;
	double	x;
	double	y_o;
	double	y;
	bool	wall;
	bool	vision;
}	t_tile;

typedef struct s_map
{
	char		**cub;
	t_element	*elements;
	int			width;
	int			height;
	int			tile_size;
	t_tile		**grid;
}	t_map;

typedef struct s_buttons
{
	bool	move_forward;
	bool	move_backward;
	bool	move_right;
	bool	move_left;
	bool	turn_right;
	bool	turn_left;
	bool	run;
	bool	minimap;
	int		tmp;
}	t_buttons;

typedef struct s_data
{
	void		*mlx;
	t_map		*map;
	t_window	*window;
	t_player	*player;
	t_buttons	*buttons;
}	t_data;

#endif