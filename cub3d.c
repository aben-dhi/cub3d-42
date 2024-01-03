/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:06 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/01/03 17:55:03 by htouil           ###   ########.fr       */
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

	if (ac == 2)
	{
		map = malloc(sizeof(t_map));
		if (!map)
			return (1);
		if (check_ext(av[1]))
		{
			free(map);
			return (ft_putstr_fd("Error\nInvalid file extension!\n", 2), 1);
		}
		init_params(map);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		read_map(fd, map);
		display_map_errors(map);
		// printf("%s\n", map->no);
		// printf("%s\n", map->so);
		// printf("%s\n", map->we);
		// printf("%s\n", map->ea);
		// printf("%s\n", map->f);
		// printf("%s\n", map->c);
		int j = 0;
		printf("rows: %d\n", map->rows);
		while (j < map->rows)
		{
			printf("%s\n", map->map[j]);
			j++;
		}
	}
	else
		return (ft_putstr_fd("Error\nInvalid number of arguments!\n", 2), 1);
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
