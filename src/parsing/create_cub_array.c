/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cub_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:35:13 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/07 14:55:36 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static int	get_number_of_lines(char *file_name)
{
	int		fd;
	int		number_of_lines;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_with_error(FILE_OPENING_ERROR);
	number_of_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		number_of_lines += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (number_of_lines);
}

char	**create_cub_array(t_map *map, char *file_name)
{
	int		number_of_lines;
	char	**cub_array;
	int		i;

	number_of_lines = get_number_of_lines(file_name);
	if (number_of_lines == 0)
		exit_with_error(EMPTY_FILE_ERROR);
	cub_array = malloc((number_of_lines + 1) * sizeof(char *));
	if (!cub_array)
		exit_with_error(MALLOC_ERROR);
	i = 0;
	while (i < number_of_lines + 1)
	{
		cub_array[i] = NULL;
		i++;
	}
	return (cub_array);
}
