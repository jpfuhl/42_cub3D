/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:35:29 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/07 15:06:12 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static void	check_if_all_set(t_element *elements, bool *all_set)
{
	int	i;
	int	set;

	i = 0;
	set = 0;
	while (i < 6)
	{
		if (elements[i].set)
			set++;
		i++;
	}
	if (set == 6)
	{
		*all_set = true;
	}
}

static void	check_element(t_map *map, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		set_texture(map, NORTH, &line[3]);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		set_texture(map, SOUTH, &line[3]);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		set_texture(map, WEST, &line[3]);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		set_texture(map, EAST, &line[3]);
	else if (line[0] == 'F' && line[1] == ' ')
		set_colour(map, FLOOR, &line[2]);
	else if (line[0] == 'C' && line[1] == ' ')
		set_colour(map, CEILING, &line[2]);
	else
		exit_with_error(ELEMENT_IDENTIFIER_ERROR);
}

static	set_element(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
		{
			check_element(map, &line[i]);
			break ;
		}
		i++;
	}
}

int	parse_elements(t_map *map, char **cub)
{
	bool	all_set;
	int		i;
	int		len;

	all_set = false;
	i = 0;
	while (cub[i] && !all_set)
	{
		if (cub[i][0] != '\0')
			set_element(map, cub[i]);
		i++;
		check_if_all_set(map->elements, &all_set);
	}
	return (i);
}
