/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:22:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 17:33:07 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/memory.h"

static void	default_initialize_image(t_image *image)
{
	image->pointer = NULL;
	image->address = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->width = 0;
	image->height = 0;
}

static t_image	*create_image(void)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		exit_with_error(MALLOC_ERROR);
	default_initialize_image(image);
	return (image);
}

void	free_window(t_window *window)
{
	free(window->screen);
	free(window->minimap);
	free(window);
}

void	default_initialize_window(t_window *window)
{
	window->pointer = NULL;
	window->width = 0;
	window->height = 0;
}

t_window	*create_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		exit_with_error(MALLOC_ERROR);
	window->screen = create_image();
	window->minimap = create_image();
	return (window);
}
