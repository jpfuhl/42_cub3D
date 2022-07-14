/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_is_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:30:31 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/14 15:30:35 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

bool	check_if_is_wall(t_tile **grid, int i, int j)
{
	if (grid[i][j].wall)
		return (true);
	return (false);
}
