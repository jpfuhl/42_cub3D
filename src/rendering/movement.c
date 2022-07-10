#include "../../inc/rendering.h"

// static int	turn(int key, t_data *data)
// {
// 	if (key == 123 || key == 12)
// 	{
// 		data->player->rotation = (data->player->rotation + 30) % 360;
// 	}
// 	if (key == 124 || key == 14)
// 	{
// 		data->player->rotation = (data->player->rotation - 30) % 360;
// 		if (data->player->rotation < 0)
// 			data->player->rotation += 360;
// 	}
// 	return (0);
// }

// static bool	movement_collision(t_data *data, double x, double y)
// {
// 	int	i;
// 	int	j;

// 	i = (data->player->x + x) / data->map->tile_size;
// 	j = (data->player->y + y) / data->map->tile_size;
// 	if (data->map->grid[i][j].wall)
// 		return (true);
// 	return (false);
// }

// static int	move_horizontal(int key, t_data *data, double x, double y)
// {
// 	if (key == 13)
// 	{
// 		fprintf(stderr, "Move %d\n", key);
// 		if (!movement_collision(data, x, -y))
// 		{
// 			data->player->x += x;
// 			data->player->y -= y;
// 			data->player->i = data->player->x / data->map->tile_size;
// 			data->player->j = data->player->y / data->map->tile_size;
// 			fprintf(stderr, "x %f y %f i %d j %d\n", data->player->x, data->player->y, data->player->i, data->player->j);
// 		}
// 	}
// 	else if (key == 1)
// 	{
// 		fprintf(stderr, "Move %d\n", key);
// 		if (!movement_collision(data, -x, y))
// 		{
// 			data->player->x -= x;
// 			data->player->y += y;
// 			data->player->i = data->player->x / data->map->tile_size;
// 			data->player->j = data->player->y / data->map->tile_size;
// 			fprintf(stderr, "x %f y %f i %d j %d\n", data->player->x, data->player->y, data->player->i, data->player->j);
// 		}
// 	}
// 	return (0);
// }

// static int	move_vertical(int key, t_data *data, double x, double y)
// {
// 	if (key == 0)
// 	{
// 		fprintf(stderr, "Move %d\n", key);
// 		if (!movement_collision(data, -x, -y))
// 		{
// 			data->player->x -= x;
// 			data->player->y -= y;
// 			data->player->i = data->player->x / data->map->tile_size;
// 			data->player->j = data->player->y / data->map->tile_size;
// 			fprintf(stderr, "x %f y %f i %d j %d\n", data->player->x, data->player->y, data->player->i, data->player->j);
// 		}
// 	}
// 	else if (key == 2)
// 	{
// 		fprintf(stderr, "Move %d\n", key);
// 		if (!movement_collision(data, x, y))
// 		{
// 			data->player->x += x;
// 			data->player->y += y;
// 			data->player->i = data->player->x / data->map->tile_size;
// 			data->player->j = data->player->y / data->map->tile_size;
// 			fprintf(stderr, "x %f y %f i %d j %d\n", data->player->x, data->player->y, data->player->i, data->player->j);
// 		}
// 	}
// 	return (0);
// }

// int	movement(int key, t_data *data)
// {
// 	double	ang_rad;
// 	double	step;

// 	ang_rad = data->player->rotation * PI / 180;
// 	step = W_WIDTH / 30;
// 	if (key == 0 || key == 2)
// 		move_vertical(key, data, step * sin(ang_rad), step * cos(ang_rad));
// 	else if (key == 13 || key == 1)
// 		move_horizontal(key, data, step * cos(ang_rad), step * sin(ang_rad));
// 	else if (key == 123 || key == 124 || key == 12 || key == 14)
// 		turn(key, data);
// 	else if (key == 53)
// 		exit(0);
// 	fprintf(stderr, "A: x %f y %f i %d j %d\n", data->player->x, data->player->y, data->player->i, data->player->j);
// 	render_frame(data, data->window->img3d);
// 	return (0);
// }

int movement(t_data *data)
{
	double	velocity;

	velocity = 1.0;
	if (data->buttons->run)
		velocity *= 2.0;
	if (data->buttons->move_forward)
		fprintf(stderr, "W\n");
	if (data->buttons->move_backward)
		fprintf(stderr, "S\n");
	if (data->buttons->move_right)
		fprintf(stderr, "D\n");
	if (data->buttons->move_left)
		fprintf(stderr, "A\n");
	if (data->buttons->turn_right)
		fprintf(stderr, ">\n");
	if (data->buttons->turn_left)
		fprintf(stderr, "<\n");
	return (0);
}