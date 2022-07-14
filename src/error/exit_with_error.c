/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:36:07 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 17:25:17 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"

static void	print_element_error_message(int type)
{
	if (type == ELEMENT_IDENTIFIER_ERROR)
		printf("Invalid element identifier.\n");
	else if (type == TEXTURE_ARGUMENT_ERROR)
		printf("Invalid texture arguments.\n");
	else if (type == DUPLICATE_TEXTURE)
		printf("Duplicate texture found.\n");
	else if (type == XPM_EXTENSION_ERROR)
		printf("Texture file with invalid extension.\n");
	else if (type == TEXTURE_ARGUMENT_ERROR)
		printf("No texture file found.\n");
	else if (type == TEXTURE_OPENING_ERROR)
		printf("Failed to open texture file.\n");
	else if (type == TEXTURE_INVALID_CONTENT)
		printf("Texture file is empty or contains junk.\n");
	else if (type == DUPLICATE_COLOUR)
		printf("Duplicate colour found.\n");
	else if (type == RGB_ARGUMENT_ERROR)
		printf("Invalid colour arguments.\n");
	else if (type == RGB_EMPTY_VALUE)
		printf("Missing RGB value(s).\n");
	else if (type == RGB_NAN)
		printf("Non-numerical RGB value(s).\n");
	else if (type == RGB_INVALID_RANGE)
		printf("One or more RGB values are out of range.\n");
}

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
	else if (type == ARGV_ERROR)
		printf("Wrong number of command line arguments.\n");
	else if (type == CUB_EXTENSION_ERROR)
		printf("Cub3D file with invalid extension.\n");
	else if (type == CUB_EMPTY_FILE)
		printf("Empty Cub3D file.\n");
	else if (type == CUB_OPENING_ERROR)
		printf("Failed to open Cub3D file.\n");
	else if (type == INVALID_TILE_SIZE)
		printf("Invalid size for tiles/textures.\n");
}

void	exit_with_error(int type)
{
	printf("Error!\n");
	if (-7 < type && type < 0)
		print_error_message(type);
	else if (-13 < type && type < -6)
		print_map_error_message(type);
	else if (-25 < type && type < -12)
		print_element_error_message(type);
	exit(type);
}
