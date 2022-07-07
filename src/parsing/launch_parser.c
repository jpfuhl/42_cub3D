/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:10:51 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/07 15:21:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	launch_parser(t_map *map, char *file_name)
{
	int	pos;

	check_cub_file_extension(file_name);
	map->cub = create_cub_array(map, file_name);
	read_cub_file(map, file_name);
	pos = parse_elements(map, map->cub);
	fprintf(stderr, "POS MAP : %d\n", pos);
	// parse_map(map, pos);
	for (int i = 0; map->cub[i]; i++)
	{
		fprintf(stderr, "%s\n", map->cub[i]);
		free(map->cub[i]);
	}
	free(map->cub);
	map->cub = NULL;
}
