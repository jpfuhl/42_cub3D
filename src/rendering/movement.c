/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:29 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 16:42:49 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static bool	active_buttons(t_buttons *buttons)
{
	if (buttons->move_forward)
		return (true);
	if (buttons->move_backward)
		return (true);
	if (buttons->move_right)
		return (true);
	if (buttons->move_left)
		return (true);
	if (buttons->turn_right)
		return (true);
	if (buttons->turn_left)
		return (true);
	return (false);
}

static void	turn(t_data *data, int rotation_speed)
{
	data->player->rotation = (data->player->rotation + rotation_speed) % 360;
	if (data->player->rotation < 0)
		data->player->rotation += 360;
}

static void	move_horizontal(t_data *data, double x, double y)
{
	if (data->buttons->move_right)
	{
		if (!movement_collision(data, -x, -y))
		{
			data->player->x -= x;
			data->player->y -= y;
			data->player->i = data->player->x / data->map->tile_size;
			data->player->j = data->player->y / data->map->tile_size;
		}
	}
	if (data->buttons->move_left)
	{
		if (!movement_collision(data, x, y))
		{
			data->player->x += x;
			data->player->y += y;
			data->player->i = data->player->x / data->map->tile_size;
			data->player->j = data->player->y / data->map->tile_size;
		}
	}
}

static void	move_vertical(t_data *data, double x, double y)
{
	if (data->buttons->move_forward)
	{
		if (!movement_collision(data, x, -y))
		{
			data->player->x += x;
			data->player->y -= y;
			data->player->i = data->player->x / data->map->tile_size;
			data->player->j = data->player->y / data->map->tile_size;
		}
	}
	if (data->buttons->move_backward)
	{
		if (!movement_collision(data, -x, y))
		{
			data->player->x -= x;
			data->player->y += y;
			data->player->i = data->player->x / data->map->tile_size;
			data->player->j = data->player->y / data->map->tile_size;
		}
	}
}

int	movement(t_data *data)
{
	double	ang_rad;
	double	velocity;
	int		rotation_speed;

	ang_rad = data->player->rotation * PI / 180;
	velocity = 0.1 * data->map->tile_size;
	rotation_speed = 5;
	if (data->buttons->run)
		velocity *= 2.0;
	if (data->buttons->move_forward)
		move_vertical(data, velocity * cos(ang_rad), velocity * sin(ang_rad));
	if (data->buttons->move_backward)
		move_vertical(data, velocity * cos(ang_rad), velocity * sin(ang_rad));
	if (data->buttons->move_right)
		move_horizontal(data, velocity * sin(ang_rad), velocity * cos(ang_rad));
	if (data->buttons->move_left)
		move_horizontal(data, velocity * sin(ang_rad), velocity * cos(ang_rad));
	if (data->buttons->turn_right)
		turn(data, rotation_speed);
	if (data->buttons->turn_left)
		turn(data, -rotation_speed);
	if (active_buttons(data->buttons))
		render_frame(data, data->window, data->mlx);
	return (0);
}
