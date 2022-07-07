/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_file_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:25:23 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/07 14:47:54 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	check_cub_file_extension(char *file_name)
{
	int		i;
	bool	dot;

	i = 0;
	dot = false;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '.')
		{
			dot = true;
			if (file_name[i + 1] != 'c')
				exit_with_error(CUB_EXTENSION_ERROR);
			if (file_name[i + 2] != 'u')
				exit_with_error(CUB_EXTENSION_ERROR);
			if (file_name[i + 3] != 'b')
				exit_with_error(CUB_EXTENSION_ERROR);
			if (file_name[i + 4] != '\0')
				exit_with_error(CUB_EXTENSION_ERROR);
			break ;
		}
		i++;
	}
	if (!dot)
		exit_with_error(CUB_EXTENSION_ERROR);
}
