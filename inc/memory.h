/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:56:49 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/06 19:28:06 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "structs.h"
# include "error.h"

# include <stdlib.h>

t_data		*create_data(void);
void		default_initialize_data(t_data *data);
void		free_data(t_data *data);

t_map		*create_map(void);
void		default_initialize_map(t_map *map);
void		free_map(t_map *map);

t_window	*create_window(void);
void		default_initialize_window(t_window *window);
void		free_window(t_window *window);

t_player	*create_player(void);
void		default_initialize_player(t_player *player);
void		free_player(t_player *player);

// t_camera	*create_camera(void);
// void		default_initialize_camera(t_camera *camera);
// void		free_camera(t_camera *camera);

#endif