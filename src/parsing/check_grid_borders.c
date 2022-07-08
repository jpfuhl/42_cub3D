/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid_borders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:43:04 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 17:19:55 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static void	check_wall(char c)
{
	if (c != '1' && c != ' ')
		exit_with_error(MAP_MISSING_WALL);
}

static void	check_orthogonal(t_tile **grid, char c, int i, int j)
{
	if (grid[i - 1][j].id == ' ' || grid[i + 1][j].id == ' ')
		check_wall(c);
	if (grid[i][j - 1].id == ' ' || grid[i][j + 1].id == ' ')
		check_wall(c);
}

static void	check_diagonal(t_tile **grid, char c, int i, int j)
{
	if (grid[i - 1][j - 1].id == ' ' || grid[i - 1][j + 1].id == ' ')
		check_wall(c);
	if (grid[i + 1][j - 1].id == ' ' || grid[i + 1][j + 1].id == ' ')
		check_wall(c);
}

static void	check_circle(t_tile **grid, char c, int i, int j)
{
	check_diagonal(grid, c, i, j);
	check_orthogonal(grid, c, i, j);
}

void	check_grid_borders(t_map *map, t_tile **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (i == 0 || i == map->width - 1)
				check_wall(grid[i][j].id);
			else if (j == 0 || j == map->height - 1)
				check_wall(grid[i][j].id);
			else
				check_circle(grid, grid[i][j].id, i, j);
			j++;
		}
		i++;
	}
}
