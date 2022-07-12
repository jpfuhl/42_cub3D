/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:53 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 19:45:09 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdlib.h>

enum e_error_type
{
	ELEMENT_IDENTIFIER_ERROR = -23,
	TEXTURE_ARGUMENT_ERROR,
	DUPLICATE_TEXTURE,
	XPM_EXTENSION_ERROR,
	TEXTURE_EMPTY_PATH,
	TEXTURE_OPENING_ERROR,
	TEXTURE_INVALID_CONTENT,
	DUPLICATE_COLOUR,
	RGB_ARGUMENT_ERROR,
	RGB_EMPTY_VALUE,
	RGB_NAN,
	RGB_INVALID_RANGE,
	MAP_EMPTY,
	MAP_EMPTY_LINE,
	MAP_INVALID_CHAR,
	MAP_NO_PLAYER,
	MAP_MULTIPLE_PLAYER,
	MAP_MISSING_WALL,
	CUB_OPENING_ERROR,
	CUB_EMPTY_FILE,
	CUB_EXTENSION_ERROR,
	ARGV_ERROR,
	MALLOC_ERROR
};

void	exit_with_error(int type);

#endif