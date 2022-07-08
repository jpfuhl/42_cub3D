/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:10:51 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 18:13:39 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	launch_parser(t_data *data, t_map *map, char *file_name)
{
	int	pos;
	int	i;

	check_cub_file_extension(file_name);
	map->cub = create_cub_array(map, file_name);
	read_cub_file(map, file_name);
	pos = parse_elements(data, map, map->cub);
	parse_map(data, map, pos);
	i = 0;
	while (map->cub[i])
	{
		free(map->cub[i]);
		i++;
	}
	free(map->cub);
	map->cub = NULL;
}
