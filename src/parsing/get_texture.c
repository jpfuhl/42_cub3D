/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resized_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:38:25 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 19:48:02 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/rendering.h"

t_image	*get_texture(t_data *data, char *path)
{
	int		pos[2];
	t_image	*texture;

	texture = malloc(sizeof(t_image));
	if (!texture)
		exit_with_error(MALLOC_ERROR);
	texture->pointer = mlx_xpm_file_to_image(data->mlx, path, &pos[0], &pos[1]);
	if (!texture->pointer)
		exit_with_error(TEXTURE_INVALID_CONTENT);
	texture->address = get_data_address(texture);
	texture->width = 128;
	texture->height = 128;
	return (texture);
}
