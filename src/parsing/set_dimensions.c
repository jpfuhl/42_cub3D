/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:02:32 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 16:57:52 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static void	check_player_count(int player)
{
	if (player == 0)
		exit_with_error(MAP_NO_PLAYER);
	else if (player > 1)
		exit_with_error(MAP_MULTIPLE_PLAYER);
}

static void	count_player(char *line, int i, int *player)
{
	if (line[i] == 'N' || line[i] == 'E' || line[i] == 'W' || line[i] == 'S')
		*player += 1;
	else
		exit_with_error(MAP_INVALID_CHAR);
}

static int	strlen_with_error_check(char *line, int *player, bool *empty_line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
			count_player(line, i, player);
		i++;
	}
	if (i == 0)
		*empty_line = true;
	if (i > 0 && *empty_line)
		exit_with_error(MAP_EMPTY_LINE);
	return (i);
}

void	set_dimensions(t_map *map, char **cub_file, int i)
{
	bool	empty_line;
	int		player;
	int		len;

	map->width = 0;
	map->height = 0;
	empty_line = false;
	player = 0;
	while (cub_file[i])
	{
		len = strlen_with_error_check(cub_file[i], &player, &empty_line);
		if (len > map->width)
			map->width = len;
		if (len > 0)
			map->height += 1;
		i++;
	}
	check_player_count(player);
	fprintf(stderr, "MAP: %d x %d\n", map->width, map->height);
}
