/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:22:15 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/08 19:07:11 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rendering.h"

static bool	movement_collision(t_window *info, double x, double y)
{
	int	i;
	int	j;

	i = (info->pos.x + x) / info->data->tile_size;
	j = (info->pos.y + y) / info->data->tile_size;
	if (check_if_is_wall(info, i, j) == true)
		return (true);
	else if (less_than_x_pixels(info, info->pos.x + x, info->pos.y + y, 1) == true)
		return (true);
	else if (going_across(info, info->pos.x + x, info->pos.y + y) == true)
	{
		printf("no puedes atravesar esquinas!\n");
		return (true);
	}
	return (false);
}

bool	less_than_x_pixels(t_window *info, double x, double y, int p)
{
	int	tile;

	tile = info->data->tile_size;
	if (check_if_is_wall(info, (x + p) / tile, (y - p) / tile) == true)
		return (true);
	if (check_if_is_wall(info, x / tile, (y - p) / tile) == true)
		return (true);
	if (check_if_is_wall(info, (x - p) / tile, (y - p) / tile) == true)
		return (true);
	if (check_if_is_wall(info, (x + p) / tile, y / tile) == true)
		return (true);
	if (check_if_is_wall(info, x / tile, y / tile) == true)
		return (true);
	if (check_if_is_wall(info, (x - p) / tile, y / tile) == true)
		return (true);
	if (check_if_is_wall(info, (x + p) / tile, (y + p) / tile) == true)
		return (true);
	if (check_if_is_wall(info, x / tile, (y + p) / tile) == true)
		return (true);
	if (check_if_is_wall(info, (x - p) / tile, (y + p) / tile) == true)
		return (true);
	return (false);
}


bool	going_across(t_window *info, double new_x, double new_y)
{
	int	old_x;
	int	old_y;
	int	old_x_copy;
	
	old_x = (int)info->pos.x;
	old_y = (int)info->pos.y;
	old_x_copy = old_x;
	while (old_x != (int)new_x)
	{
		if (old_x < (int)new_x)
			old_x++;
		else
			old_x--;
		if (check_if_is_wall(info, old_x / info->data->tile_size, old_y / info->data->tile_size) == true)
			return (true);
	}
	while (old_y != (int)new_y)
	{
		if (old_y < (int)new_y)
			old_y++;
		else
			old_y--;
		if (check_if_is_wall(info, old_x_copy / info->data->tile_size, old_y / info->data->tile_size) == true)
			return (true);
	}
	return (false);
}

bool	check_if_is_wall(t_window *info, int i, int j)
{
	if (info->data->map[i][j].wall)
		return (true);
	else
		return (false);
}

int	key_handler_arrow(int key, t_player *player)
{
	if (key == 123 || key == 12)
	{
		player->rotation = (player->rotation + 20) % 360;
	}
	if (key == 124 || key == 14)
	{
		player->rotation = (player->rotation - 20) % 360;
		if (player->rotation < 0)
			player->rotation += 360;
	}
	return (0);
}

/*
* arrow a(0), w(13), s(1), d(2)
* arrows left(123), right(124)
*/
int	key_handler(int key, t_data *data)
{
	double	ang_rad;
	double	step;

	ang_rad = data->player->rotation * PI / 180;
	step = data->map->tile_size / 8.0;
	if (key == 0)
	{
		if (!movement_collision(info, -step * sin(ang_rad), -step * cos(ang_rad)))
		{
			info->pos.x -= step * (sin(ang_rad));
			info->pos.y -= step * (cos(ang_rad));
		}
	}
	else if (key == 2)
	{
		if (!movement_collision(info, step * sin(ang_rad), step * cos(ang_rad)))
		{
			info->pos.x += step * (sin(ang_rad));
			info->pos.y += step * (cos(ang_rad));
		}
	}
	else if (key == 13)
	{
		if (!movement_collision(info, step * cos(ang_rad), -step * sin(ang_rad)))
		{
			info->pos.x += step * (cos(ang_rad));
			info->pos.y -= step * (sin(ang_rad));
		}
	}
	else if (key == 1)
	{
		if (!movement_collision(info, -step * cos(ang_rad), step * sin(ang_rad)))
		{
			info->pos.x -= step * (cos(ang_rad));
			info->pos.y += step * (sin(ang_rad));
		}
	}
	if (key == 53)
		exit (0);
	else if (key == 123 || key == 124 || key == 12 || key == 14)
		key_handler_arrow(key, data->player);
	render_frame(data, data->mlx, data->window->screen);
	return (0);
}

