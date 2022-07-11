#ifndef RENDERING_H
# define RENDERING_H

# include "structs.h"
# include "../libmlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void	render_frame(t_data *data, t_window *window, void *mlx);

/*	DRAWING PARTS OF IMAGE */
void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_background(t_image *image, t_element *elements);
void	draw_player(t_data *data, t_image *image, double x, double y);
void	draw_square(t_image *image, int tile_size, int dx, int dy, int color);
void	draw_map(t_data *data, t_image *image);
void	draw_minimap();
// void	draw_square(t_image *image, int tile_size, int dx, int dy, int color);


void	create_image(t_data *data, t_image **image, int width, int height);
char	*get_data_address(t_image *image);
void	resize_image(t_image *destination, t_image *source);
int		get_pixel_from_source(t_image *dst, t_image *src, int x, int y);
int		get_pixel_colour(t_image *image, int x, int y);

/*	MOVEMENT */
void	keyhooks(t_data *data, t_window *window, void *mlx);
int		movement(t_data *data);
bool	movement_collision(t_data *data, double x, double y);

/* DDA - ALGORITHM */
int	dda_algorithm_punk(t_data *data, double player_x, double player_y, t_xy p2);
void color_point(t_data *data, double x, double y, int i);

/* RAYCASTING */
void    my_mlx_pixel_put(t_image *img, int x, int y, int color);
int raycasting(t_data *data, double factor);
t_xy    find_coalition(t_data *data, t_ray *ray);
void    deltaDist(t_ray *ray);
void    sideDist(t_data *data, t_ray *ray);
t_xy    first_int_X(t_data *data, t_ray *ray);
t_xy    first_int_Y(t_data *data, t_ray *ray);
t_xy    intersection_X(t_data *data, t_ray *ray);
t_xy    intersection_Y(t_data *data, t_ray *ray);

/* check_wall_coallision.c */
bool    check_wall_collision(t_data *data, t_ray *ray, t_xy vector, int x, int y);


#endif