#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

# define WINDOW_WIDTH	1024
# define WINDOW_HEIGHT	1024
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
	t_xy		vector;
	int			c_mapx;
	int			c_mapy;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			axis;
	int			colour;
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
	char	*path; // remove
	void	*texture;
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
}	t_tile;

typedef struct s_map
{
	char		**cub;
	t_element	*elements;
	int			width;
	int			height;
	double		tile_size;
	t_tile		**grid;
}	t_map;


typedef struct s_data
{
	void		*mlx;
	t_map		*map;
	t_window	*window;
	t_player	*player;
}	t_data;

#endif