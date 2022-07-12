/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:56:49 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 19:06:16 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "../libmlx/mlx.h"
# include "structs.h"
# include "error.h"

# include <stdlib.h>

t_data		*create_data(void);
void		default_initialize_data(t_data *data);
void		free_data(t_data *data);

t_map		*create_map(void);
void		default_initialize_map(t_map *map);
void		free_map(void *mlx, t_map *map);

t_window	*create_window(void);
void		default_initialize_window(t_window *window);
void		free_window(t_window *window);

t_player	*create_player(void);
void		default_initialize_player(t_player *player);
void		free_player(t_player *player);

t_buttons	*create_buttons(void);
void		default_initialize_buttons(t_buttons *buttons);
void		free_buttons(t_buttons *buttons);

// t_camera	*create_camera(void);
// void		default_initialize_camera(t_camera *camera);
// void		free_camera(t_camera *camera);

#endif