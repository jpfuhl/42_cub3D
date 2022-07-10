#ifndef RENDERING_H
# define RENDERING_H

# include "structs.h"
# include "../libmlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void	render_frame(t_data *data, void *mlx, t_image *screen);

/*	DRAWING PARTS OF IMAGE */
void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_player(t_data *data, t_image *image, double x, double y);
void	draw_minimap(t_data *data, t_image *image);
// void	draw_square(t_image *image, int tile_size, int dx, int dy, int color);


int	key_handler(int key, t_data *data);
void	keyhooks(t_data *data, t_window *window, void *mlx);
int		movement(t_data *data);
#endif