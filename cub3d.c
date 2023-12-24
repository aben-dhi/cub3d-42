/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:06 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/09 17:37:33 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//we're goinf to proceed with checking the map first
//then we'll proceed with the window
//the first thing we need to do is to check if the map is valid
//extension is .cub
//we'll do that by checking if the map is surrounded by walls
//
void init_params(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->file = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = NULL;
	map->tmp = NULL; 
	map->f = NULL;
	map->c = NULL;
	map->posx = 1;
	map->posy = 1;
}

int	check_ext(char *file)
{
	char *ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 4) != 0)
		return (1);
	return (0);
}	

int main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	if (argc == 2)
	{
        if (check_ext(argv[1]))
        {
            printf("Error\nInvalid file extension\n");
            free(map);
            return (0);
        }
		
		init_params(map);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (0);
		if (!read_map(fd, map, argv[1]))
			printf("Error\nInvalid map\n");
		save_dir(map);
		// save_fc(map);
		int pos = save_fc(map) + 2;
		save_map(map, pos);
		save_tmp(map);
		// printf("height = %d\n", map->height);
		if (checkwalls(map->posx, map->posy, map) == 0)
			printf("Error\nInvalid map\n");
		close(fd);
		int j = 0;
		while (j < map->height)
		{
			printf("%s\n",map->map[j]);
			j++;
		}
		// int i = 0;
		// while (i < map->height)
		// {
		// 	printf("%s\n", map->tmp[i]);
		// 	i++;
		// }
	}
	else
		printf("Error\nInvalid number of arguments\n");
	free(map);
	return (0);
}

