/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 17:31:05 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

typedef struct s_minimap
{
	int		size;
	int		factor;
	double	x_start;
	double	y_start;
	double	tmp;
	double	step;
}	t_minimap;

static int	pick_colour(void)
{
	static int	i = 0;
	int			colour;

	if (i < 1000)
		colour = 0xf1c937;
	else if (2000 <= i && i < 4000)
		colour = 0x00babc;
	else if (4000 <= i && i < 6000)
		colour = 0xf1c937;
	else if (6000 <= i && i < 8000)
		colour = 0xd101c0;
	i++;
	if (i == 8000)
		i = 0;
	return (colour);
}

static void	check_tile(t_data *data, t_minimap *mini, int i, int j)
{
	t_tile	**grid;
	int		x;
	int		y;
	int		colour;

	grid = data->map->grid;
	x = (int)mini->x_start;
	y = (int)mini->y_start;
	if (grid[x][y].id == '1' || grid[x][y].id == ' ')
	{
		if (grid[x][y].vision)
		{
			colour = pick_colour();
			draw_pixel(data->window->minimap, i, j, colour);
		}
	}
	else
		draw_pixel(data->window->minimap, i, j, 0x18191a);
}

static bool	check_limits(t_data *data, t_minimap *mini, int i, int j)
{
	double	limit_x;
	double	limit_y;

	limit_x = 1.0 * data->map->width;
	limit_y = 1.0 * data->map->height;
	if (mini->x_start < 0 || mini->y_start < 0)
		draw_pixel(data->window->minimap, i, j, 0x0a0a0a);
	else if (mini->x_start >= limit_x || mini->y_start >= limit_y)
		draw_pixel(data->window->minimap, i, j, 0x0a0a0a);
	else
		return (false);
	return (true);
}

static void	init_minimap(t_minimap *mini, double x, double y)
{
	mini->size = 225;
	mini->factor = 9;
	mini->x_start = x - mini->factor / 2 - 1;
	mini->y_start = y - mini->factor / 2 - 1;
	mini->tmp = mini->y_start;
	mini->step = 1.0 * mini->factor / mini->size;
}

void	draw_minimap(t_data *data, t_map *map, t_player *player, t_image *img)
{
	t_minimap	mini;
	int			i;
	int			j;
	int			colour;

	init_minimap(&mini, player->x / TEXTURE_SIZE, player->y / TEXTURE_SIZE);
	i = 0;
	while (i < mini.size)
	{
		j = 0;
		mini.y_start = mini.tmp;
		while (j < mini.size)
		{
			if (!check_limits(data, &mini, i, j))
				check_tile(data, &mini, i, j);
			mini.y_start += mini.step;
			j++;
		}
		mini.x_start += mini.step;
		i++;
	}
	draw_player(data, img, 125.0, 125.0);
}
