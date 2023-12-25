/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:42:20 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/25 23:39:36 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//we need to skip all the lines that are not part of the map
//we need to save the map in a 2d array map->map
//we need to save the width and height of the map
// void	save_map(t_map *map)
// {
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	while (i < map->height && map->file[i])
// 	{
// 		j = 0;
// 		while (map->file[i][j] != '\0')
// 		{
// 			if (map->file[i][j] == '1')
// 			{
// 				map->map[k] = ft_substr(map->file[i], j, ft_strlen(map->file[i]));
// 				k++;
// 				if (map->width < ft_strlen1(map->file[i]))
// 					map->width = ft_strlen1(map->file[i]);
// 				map->height++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void save_map(t_map *map)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while (i < map->height && map->file[i])
//     {
//         j = 0;
//         while (map->file[i][j] != '\0')
//         {
//             if (map->file[i][j] == '1')
//             {
//                 map->map[i] = ft_substr(map->file[i], j, ft_strlen(map->file[i]));
//                 if (map->width < ft_strlen1(map->file[i]))
//                     map->width = ft_strlen1(map->file[i]);
//                 map->height++;
//                 break;
//             }
//             j++;
//         }
//         i++;
//     }
// }

//we have pos as the last line before the map starts in map->file
//we need to save the map in map->map
//now map->height is the number of lines in the map which is the initial height minus pos
//we need to save the width of the map in map->width
void	save_map(t_map *map, int pos)
{
	// pos++;
	int	i;

	i = 0;
	// printf("pos = %d\n", pos);
	map->map = malloc(sizeof(char *) * (map->height - pos + 1));
	if (!map->map)
		return ;
	map->width = 0;
	while (pos <= map->height && map->file[pos])
	{
		if (map->file[pos][0] == '\0' || map->file[pos][0] == ' ')
			pos++;
		// printf("%d\n", i);
		// printf("map->file[%d] = %s\n", pos, map->file[pos]);
		// else
		map->map[i] = ft_strdup(map->file[pos]);
		if (map->width < ft_strlen1(map->file[pos]))
			map->width = ft_strlen1(map->file[pos]);
		pos++;
		i++;
	}
	map->height = i;
	map->map[i] = NULL;
}

// void save_map(t_map *map, int pos) {
//     int i = 0;

// //     // Free existing memory
//     // if (map->map) {
//     //     for (int j = 0; j < map->height; j++) {
//     //         free(map->map[j]);
//     //     }
//     //     free(map->map);
//     // }

//     map->map = malloc(sizeof(char *) * (map->height - pos + 1));
//     if (!map->map) {
//         return;
//     }

//     map->width = 0;

//     // Copy lines from map->file to map->map
//     while (pos <= map->height && map->file[pos])
//     {
//         map->map[i] = ft_strdup(map->file[pos]);
//         if (map->width < ft_strlen1(map->file[pos])) {
//             map->width = ft_strlen1(map->file[pos]);
//         }
//         pos++;
//         i++;
//     }

//     map->height = i;
//     map->map[i] = NULL;
// }


//save a temporary map in map->tmp
//we need to save the map without the spaces in map->tmp
//we already have the height updated in map->height
void    save_tmp(t_map *map)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	map->tmp = malloc(sizeof(char *) * (map->height + 1));
	if (!map->tmp)
		return ;
	while (i < map->height && map->map[i])
	{
		j = 0;
		k = 0;
		map->tmp[i] = malloc(sizeof(char) * (ft_strlen1(map->map[i]) + 1));
		if (!map->tmp[i])
			return ;
		while (map->map[i][j] != '\0' && map->map[i])
		{
			if (!ft_isspace(map->map[i][j]))
			{
				map->tmp[i][k] = map->map[i][j];
				k++;
			}
			j++;
		}
		map->tmp[i][k] = '\0';
		i++;
	}
	map->tmp[i] = NULL;
}

