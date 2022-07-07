/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:21:17 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/07 14:17:51 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	/*
	- Create && initialize data and all the needed structs
	- Parse the given map
	- Launch Game
	- free data
	*/
	t_data	*data;

	if (argc != 2)
		exit_with_error(ARGV_ERROR);
	data = create_data();
	fprintf(stderr, "Created data! whoosh %p\n", data);
	data->mlx = mlx_init();
	launch_parser(data->map, argv[1]);
	fprintf(stderr, "Parsed data! whoosh\n");
	free_data(data);
	fscanf(stdin, "c");
	return (0);
}
