#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "structs.h"
# include "error.h"
# include "memory.h"

# include "rendering.h"

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

// void	raycasting(t_data *data, t_window *window, t_image *screen);

// void	calculate_ray(t_data *data, t_ray *ray, float i);

// t_xy	find_collision_point(t_data *data, t_ray *ray);
// t_xy	first_intersection_x(t_data *data, t_tile **grid, t_player *player, t_ray *ray);
// t_xy	first_intersection_y(t_data *data, t_tile **grid, t_player *player, t_ray *ray);
// t_xy	intersection_x(t_data *data, t_tile **grid, t_player *player, t_ray *ray);
// t_xy	intersection_y(t_data *data, t_tile **grid, t_player *player, t_ray *ray);
// bool	check_wall_collision(t_data *data, t_tile **grid, t_ray *ray, t_xy intersection);

// void	calculate_delta_distance(t_ray *ray);
// void	calculate_side_distance(t_data *data, t_player *player, t_ray *ray);
void	calculate_perp_wall_distance(t_player *player, t_ray *ray);

void	calculate_line_position(t_ray *ray, t_xy intersection, int tile_size);
void	calculate_line_height(t_data *data, t_window *window, t_ray *ray);

// void	calculate_plane_vector(t_data *data, t_ray *ray, float i);
// int		dda_algorithm(t_data *data, float x1, float y1, float x2, float y2);

#endif