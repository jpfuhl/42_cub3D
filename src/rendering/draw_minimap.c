#include "../../inc/rendering.h"

static void	draw_square(t_image *image, int tile_size, int dx, int dy, int color)
{
	int	i;
	int	j;

	j = 1 + dy * tile_size;
	while (j < tile_size - 1 + dy * tile_size)
	{
		i = 1 + dx * tile_size;
		while (i < tile_size - 1 + dx * tile_size)
		{
			draw_pixel(image, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_data *data, t_image *image)
{
	int	colour;
	int	j;
	int	i;

	colour = 0;
	i = 0;
	while (i < data->map->width)
	{
		j = 0;
		while (j < data->map->height)
		{
			if (data->map->grid[i][j].id == '1')
			{
				colour = 0x36454F;
				draw_square(image, data->map->tile_size, i, j, colour);
			}
			else if (data->map->grid[i][j].id == '0')
			{
				colour = 0x949494;
				draw_square(image, data->map->tile_size, i, j, colour);
			}
			else if (data->map->grid[i][j].id == 'N' || data->map->grid[i][j].id == 'S' || data->map->grid[i][j].id == 'E' || data->map->grid[i][j].id == 'W')
			{
				colour = 0x949494;
				draw_square(image, data->map->tile_size, i, j, colour);
			}
			j++;
		}
		i++;
	}
}
