/* ************************************************************************** */


#include "../../inc/rendering.h"

void	draw_player(t_data *data, t_image *image, double x, double y)
{
	int	i;
	int	j;
	double	ang_rad;

	ang_rad = data->player->rotation * 3.14159 / 180;
	i = 0;
	j = 0;
	while (i < 40)
	{
		draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (j),
			y - (sin(ang_rad) * (i) + cos(ang_rad) * (j)), 0x00FF0000);
		i++;
	}
	while (i > 30)
	{
		draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (j),
			y - (sin(ang_rad) * (i) + cos(ang_rad) * (j)), 0x00FF0000);
		draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (-j),
			y - (sin(ang_rad) * (i) + cos(ang_rad) * (-j)), 0x00FF0000);
		j++;
		i--;
	}
}
