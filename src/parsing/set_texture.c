/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:36:04 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/07 15:13:19 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static void	check_xpm_file_extension(char *file_name)
{
	int		i;
	bool	dot;

	i = 0;
	dot = false;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '.')
		{
			dot = true;
			if (file_name[i + 1] != 'x')
				exit_with_error(XPM_EXTENSION_ERROR);
			if (file_name[i + 2] != 'p')
				exit_with_error(XPM_EXTENSION_ERROR);
			if (file_name[i + 3] != 'm')
				exit_with_error(XPM_EXTENSION_ERROR);
			if (file_name[i + 4] != '\0')
				exit_with_error(XPM_EXTENSION_ERROR);
		}
		i++;
	}
	if (!dot)
		exit_with_error(XPM_EXTENSION_ERROR);
}

static bool	check_path(char *path)
{
	int	fd;

	check_xpm_file_extension(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error(TEXTURE_PATH_ERROR);
	close (fd);
	return (true);
}

static char	*get_path(char *line)
{
	char	**split;
	int		i;
	char	*path;

	split = ft_split(line, ' ');
	if (!split)
		exit_with_error(MALLOC_ERROR);
	i = 0;
	while (split[i])
		i += 1;
	if (i != 1)
		exit_with_error(ELEMENT_ARGUMENT_ERROR);
	path = ft_strdup(split[0]);
	if (!path)
		exit_with_error(MALLOC_ERROR);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	check_path(path);
	return (path);
}

static char	*parse_path(char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
		{
			path = get_path(&line[i]);
			break ;
		}
		i++;
	}
	if (line[i] == '\0')
		exit_with_error(EMPTY_PATH);
	return (path);
}

void	set_texture(t_map *map, int type, char *line)
{
	char	*path;

	if (map->elements[type].set)
		exit_with_error(DUPLICATE_ELEMENT_ERROR);
	map->elements[type].path = parse_path(line);
	// open image;
	// resize image;
	map->elements[type].set = true;
	fprintf(stderr, "%d %s\n", type, line);
}
