#ifndef CUB3D_H
# define CUB3D_H


# include "../libft/includes/libft.h"
# include "../libmlx/mlx.h"
# include "structs.h"
# include "error.h"
# include "memory.h"

# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
//We will use:
# include <math.h>
# include <limits.h>



// error.h
// memory.h
// parsing.h
// rendering.h

# define WINDOW_WIDTH	1024
# define WINDOW_HEIGHT	1024
# define PI				3.141592

enum e_texture_type
{
	DEFAULT = -1,
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING
};



/*	MOVEMENT */


#endif