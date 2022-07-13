/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:42:24 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 11:59:33 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* RAYCASTING */
void	raycasting(t_data *data, double factor);
t_xy	find_collision(t_data *data, t_ray *ray);
void	deltaDist(t_ray *ray);
void	sideDist(t_data *data, t_ray *ray);
t_xy	first_int_X(t_data *data, t_ray *ray);
t_xy	first_int_Y(t_data *data, t_ray *ray);
t_xy	intersection_X(t_data *data, t_ray *ray);
t_xy	intersection_Y(t_data *data, t_ray *ray);

/* check_walls.c */
bool	west_wall(t_data *data, t_ray *ray, int i, int j);
bool	east_wall(t_data *data, t_ray *ray, int i, int j);
bool	south_wall(t_data *data, t_ray *ray, int i, int j);
bool	north_wall(t_data *data, t_ray *ray, int i, int j);
bool	northwest(t_data *data, t_ray *ray, int i, int j);

/* check_wall_coallision.c */
void	disco_wall(t_data *data, int dx, int dy);
bool	check_wall_collision(t_data *data, t_ray *ray, t_xy vector, t_xy inter);
bool	check_borders(t_data *data, t_ray *ray, t_xy vector, t_xy inter);
bool	left_border(t_data *data, t_ray *ray, t_xy vector, t_xy inter);
bool	right_border(t_data *data, t_ray *ray, t_xy vector, t_xy inter);

void	calculate_perp_wall_distance(t_player *player, t_ray *ray);
void	calculate_line_position(t_ray *ray, t_xy intersection, int tile_size);
void	calculate_line_height(t_data *data, t_window *window, t_ray *ray);

// void	calculate_plane_vector(t_data *data, t_ray *ray, float i);

/* DDA - ALGORITHM */
int		dda_algorithm_punk(t_data *data, double player_x, double player_y, t_xy p2);

#endif