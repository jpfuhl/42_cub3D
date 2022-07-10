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


void	create_image(t_data *data, t_image **image, int width, int height);
char	*get_data_address(t_image *image);


/*	MOVEMENT */
void	keyhooks(t_data *data, t_window *window, void *mlx);
int		movement(t_data *data);
bool	movement_collision(t_data *data, double x, double y);

#endif