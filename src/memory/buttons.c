/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:55:44 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 16:35:55 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/memory.h"

void	free_buttons(t_buttons *buttons)
{
	free(buttons);
}

void	default_initialize_buttons(t_buttons *buttons)
{
	buttons->move_forward = false;
	buttons->move_backward = false;
	buttons->move_right = false;
	buttons->move_left = false;
	buttons->turn_right = false;
	buttons->turn_left = false;
	buttons->run = false;
	buttons->minimap = false;
	buttons->tmp = 1;
}

t_buttons	*create_buttons(void)
{
	t_buttons	*buttons;

	buttons = malloc(sizeof(t_buttons));
	if (!buttons)
		exit_with_error(MALLOC_ERROR);
	return (buttons);
}
