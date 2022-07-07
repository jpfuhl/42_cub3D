/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:38:25 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/07 18:41:56 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"







t_image	*get_texture(void *mlx, char *path)
{
	int		pos[2];
	void	*tmp;
	void	*texture;

	tmp = mlx_xpm_file_to_image(mlx, path, &pos[0], &pos[1]);
	resize_image();
	return (texture);
}