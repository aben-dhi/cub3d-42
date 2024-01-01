/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:06 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/31 20:32:14 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//we're going to proceed with checking the map first
//then we'll proceed with the window
//the first thing we need to do is to check if the map is valid
//extension is .cub
//we'll do that by checking if the map is surrounded by walls
//
void	init_params(t_map *map)
{
	map->rows = 0;
	map->columns = 0;
	map->file = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	map->map = NULL;
	map->tmp = NULL; 
	map->posx = 1;
	map->posy = 1;
}

int	check_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	if (ac == 2)
	{
		if (check_ext(av[1]))
		{
			ft_putstr_fd("Error\nInvalid file extension!\n", 2);
			free(map);
			return (1);
		}
		init_params(map);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		read_map(fd, map); //LAST MODIFICATION HERE!!!
		display_map_errors(map);
		// save_dir(map);
		// save_fc(map);
		// int pos = save_fc(map) + 2;
		// save_map(map, pos);
		// save_tmp(map);
		// // printf("rows = %d\n", map->rows);
		// if (checkwalls(map->posx, map->posy, map) == 0)
		// 	printf("Error\nInvalid map\n");
		// close(fd);
		// printf("rows=%d\n", map->rows);
		int j = 0;
		printf("rows: %d\n", map->rows);
		while (j < map->rows)
		{
			printf("%s\n", map->map[j]);
			j++;
		}
		// printf("line 0: (%s) [len=%d]\n", map->map[0], ft_strlen1(map->map[0]));
		// printf("1: (%c)\n", map->map[0][0]);
		// printf("line 10: (%s) [len=%d]\n", map->map[10], ft_strlen1(map->map[10]));
		// printf("2: (%c)\n", map->map[map->rows - 1][ft_strlen1(map->map[map->rows - 1]) - 1]);
		// int i = 0;
		// while (i < map->rows)
		// {
		// 	printf("%s\n", map->tmp[i]);
		// 	i++;
		// }
	}
	else
	{
		ft_putstr_fd("Error\nInvalid number of arguments!\n", 2);
		free(map);
		return (1);
	}
	free(map);
	return (0);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	if (!line)
// 	{
// 		printf("shit");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		if (!line)
// 		{
// 			printf("shit");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	if (line)
// 		printf("1: %s(yes)\n", line);
// 	else
// 		printf("1: %s(no)\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	if (line)
// 		printf("2: %s(yes)\n", line);
// 	else
// 		printf("2: %s(no)\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	if (line)
// 		printf("3: %s(yes)\n", line);
// 	else
// 		printf("3: %s(no)\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	if (line)
// 		printf("4: %s(yes)\n", line);
// 	else
// 		printf("4: %s(no)\n", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	int		i;
// 	int		*len = NULL;
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	i = 0;
// 	line = get_next_line(fd);
// 	printf("ZEBBI");
// 	// len = malloc (3 * sizeof(int));
// 	len = ft_calloc(3, 4);
// 	len[i] = ft_strlen1(line) - 1;
// 	printf("1: %s(%d)\n", line, len[i++]);
// 	free(line);
// 	line = get_next_line(fd);
// 	len[i] = ft_strlen1(line) - 1;
// 	printf("2: %s(%d)\n", line, len[i++]);
// 	free(line);
// 	line = get_next_line(fd);
// 	len[i] = ft_strlen1(line) - 1;
// 	printf("3: %s(%d)\n", line, len[i++]);
// 	free(line);
// 	close(fd);
// }
