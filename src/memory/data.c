/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:22:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/06 19:19:20 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/memory.h"

void	free_data(t_data *data)
{
	free_map(data->map);
	free_window(data->window);
	free_player(data->player);
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
	default_initialize_data(data);
	return (data);
}
