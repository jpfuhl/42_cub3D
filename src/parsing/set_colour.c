/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:35:52 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 17:35:29 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static bool	check_digits(char *value)
{
	int	i;

	i = 0;
	while (value[i] != '\0')
	{
		if (value[i] < '0' || '9' < value[i])
			exit_with_error(RGB_NAN);
		i++;
	}
	return (true);
}

static int	set_number(char *value)
{
	char	**split;
	int		i;
	int		number;

	split = ft_split(value, ' ');
	if (!split)
		exit_with_error(MALLOC_ERROR);
	i = 0;
	while (split[i])
		i += 1;
	if (i != 1)
		exit_with_error(RGB_ARGUMENT_ERROR);
	check_digits(split[0]);
	number = ft_atoi(split[0]);
	if (number < 0 || 255 < number)
		exit_with_error(RGB_INVALID_RANGE);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (number);
}

static void	parse_value(t_element *element, int n, char *value)
{
	int	i;

	i = 0;
	while (value[i] != '\0')
	{
		if (value[i] != ' ')
		{
			if (n == 0)
				element->r = set_number(value);
			else if (n == 1)
				element->g = set_number(value);
			else if (n == 2)
				element->b = set_number(value);
			break ;
		}
		i++;
	}
	if (value[i] == '\0')
		exit_with_error(RGB_EMPTY_VALUE);
}

static void	check_commas(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			comma += 1;
		i++;
	}
	if (comma != 2)
		exit_with_error(RGB_ARGUMENT_ERROR);
}

void	set_colour(t_map *map, int type, char *line)
{
	char	**split;
	int		i;

	if (map->elements[type].set)
		exit_with_error(DUPLICATE_COLOUR);
	check_commas(line);
	split = ft_split(line, ',');
	i = 0;
	while (split[i])
	{
		parse_value(&map->elements[type], i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	map->elements[type].colour = convert_rgb_to_hex(&map->elements[type]);
	map->elements[type].set = true;
}
