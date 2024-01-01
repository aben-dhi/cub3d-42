/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:39:37 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/27 17:35:40 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//we're going to check the map->tmp instead of map->map because we skiped the spaces and empty lines
//for columns and for rows we're going to check the first and last character of the map
//the character has to be 1

// int	checkwalls(int x, int y, t_map *map)
// {
// 	if (x < 0 || x >= map->columns || y < 0 || y >= map->rows)
// 		return (1);
// 	// Skip spaces within the map
// 	if (map->map[x][y] == ' ' || map->map[x][y] == '\0'\
// 	|| map->map[x][y] == '\n')
// 		return checkwalls(x, y + 1, map); // Move to the next position
// 	// Base case: if current position is '0'
// 	if (map->map[x][y] == '0' && map->map[x][y] != '1')
// 		return (0); // Invalid

// 	// Mark the current position as visited (optional, depending on your needs)

// 	// Recursively check surrounding positions
// 	return checkwalls(x + 1, y, map) && // Down
// 		checkwalls(x - 1, y, map) && // Up
// 		checkwalls(x, y + 1, map) && // Right
// 		checkwalls(x, y - 1, map);   // Left
// }
