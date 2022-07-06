/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:36:07 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/06 19:35:32 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"

static void	print_map_error_message(int type)
{
	if (type == MAP_EMPTY)
		printf("No map found.\n");
	else if (type == MAP_EMPTY_LINE)
		printf("Empty line in map.\n");
	else if (type == MAP_INVALID_CHAR)
		printf("Invalid char in map.\n");
	else if (type == MAP_NO_PLAYER)
		printf("No player position found.\n");
	else if (type == MAP_MULTIPLE_PLAYER)
		printf("Multiple player positions found.\n");
	else if (type == MAP_MISSING_WALL)
		printf("Map has to be surrounded by walls.\n");
}

static void	print_error_message(int type)
{
	if (type == MALLOC_ERROR)
		printf("Failed to allocate memory with malloc.\n");
	else if (type == FILE_OPENING_ERROR)
		printf("Failed to open .cub file.\n");
	else if (type == EMPTY_FILE_ERROR)
		printf("Empty .cub file.\n");
	else if (type == ELEMENT_ARGUMENT_ERROR)
		printf("Invalid element arguments.\n");
	else if (type == ELEMENT_TYPE_ERROR)
		printf("Invalid element type.\n");
	else if (type == DUPLICATE_ELEMENT_ERROR)
		printf("Duplicate element type.\n");
	else if (type == TEXTURE_PATH_ERROR)
		printf("Failed to open texture path.\n");
	else if (type == RGB_NAN_ERROR)
		printf("Non-numerical RGB values.\n");
	else if (type == RGB_RANGE_ERROR)
		printf("RGB values are out of range.\n");
	else if (-7 < type && type < 0)
		print_map_error_message(type);
}

void	exit_with_error(int	type)
{
	printf("Error!\n");
	//	if -1 - -4 ?
	print_error_message(type);
	// if element <>
	// print_element_error_message;
	// if map <>
	// print_map_error_message;
	exit(type);
}


// element_error
// map_error