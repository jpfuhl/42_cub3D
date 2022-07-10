/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:22:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 16:13:24 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/memory.h"




t_buttons	*create_buttons(void)
{
	t_buttons	*buttons;

	buttons = malloc(sizeof(t_buttons));
	if (!buttons)
		exit_with_error(MALLOC_ERROR);
	buttons->move_forward = false;
	buttons->move_backward = false;
	buttons->move_right = false;
	buttons->move_left = false;
	buttons->turn_right = false;
	buttons->turn_left = false;
	buttons->run = false;
	return (buttons);
}


void	free_data(t_data *data)
{
	free_map(data->mlx, data->map);
	free_window(data->window);
	free_player(data->player);
	free(data->buttons);
}

void	default_initialize_data(t_data *data)
{
	data->mlx = NULL;
	default_initialize_map(data->map);
	default_initialize_window(data->window);
	default_initialize_player(data->player);
}

t_data	*create_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_with_error(MALLOC_ERROR);
	data->map = create_map();
	data->window = create_window();
	data->player = create_player();
	data->buttons = create_buttons();
	default_initialize_data(data);
	return (data);
}
