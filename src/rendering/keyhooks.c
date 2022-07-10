#include "../../inc/rendering.h"
#include "../../inc/memory.h"

static int	close_window(t_data *data)
{
	free_data(data);
	exit (0);
	return (0);
}

static int	release_buttons(int key, t_data *data)
{
	if (key == 13 || key == 126)
		data->buttons->move_forward = false;
	else if (key == 1 || key == 125)
		data->buttons->move_backward = false;
	else if (key == 0)
		data->buttons->move_right = false;
	else if (key == 2)
		data->buttons->move_left = false;
	else if (key == 12 || key == 123)
		data->buttons->turn_right = false;
	else if (key == 14 || key == 124)
		data->buttons->turn_left = false;
	else if (key == 257)
		data->buttons->run = false;
	return (0);
}

static int press_buttons(int key, t_data *data)
{
	if (key == 53)
		close_window(data);
	else if (key == 13 || key == 126)
		data->buttons->move_forward = true;
	else if (key == 1 || key == 125)
		data->buttons->move_backward = true;
	else if (key == 0)
		data->buttons->move_right = true;
	else if (key == 2)
		data->buttons->move_left = true;
	else if (key == 12 || key == 123)
		data->buttons->turn_right = true;
	else if (key == 14 || key == 124)
		data->buttons->turn_left = true;
	else if (key == 257)
		data->buttons->run = true;
	return (0);
}

void	keyhooks(t_data *data, t_window *window, void *mlx)
{
	mlx_hook(window->pointer, 02, 0L, &press_buttons ,data);
	mlx_hook(window->pointer, 03, 0L, &release_buttons, data);
	mlx_hook(window->pointer, 17, 0, &close_window, data);
	mlx_loop_hook(mlx, &movement, data);
}