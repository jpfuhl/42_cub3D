/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:22:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/06/13 20:27:27 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/memory.h"

void	free_player(t_player *player)
{
	free(player);
}

void	default_initialize_player(t_player *player)
{
	player->i = 0;
	player->j = 0;
	player->x = 0;
	player->y = 0;
	player->rotation = 0;
}

t_player	*create_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		exit_with_error(MALLOC_ERROR);
	return (player);
}
