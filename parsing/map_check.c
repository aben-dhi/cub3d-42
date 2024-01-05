/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:33:03 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/01/04 20:04:04 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int check_extension(char *file)
// {
// 	if (ft_strncmp(ft_strrchr(file, '.'), ".cub", 4) == 0)
// 		return (1);
// 	return (0);
// }

// int	map_check(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' 
// 			&& line[i] != 'S' && line[i] != 'E' &&
// 			line[i] != 'W' && line[i] != ' ')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_walls(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] != '1' && line[i] != ' ')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	read_map(int fd, t_map *map, char *path)
// {
// 	char	*line;
// 	char	*count;
// 	int		i;

// 	i = 0;
// 	count = NULL;
// 	if (get_next_line(fd) == NULL)
// 	{
// 		ft_putstr_fd("Error\nInvalid file!\n", 2);
// 		return (-1);
// 	}
// 	while ((count = get_next_line(fd)) && *count != '\0')
// 	{
// 		map->rows++;
// 		free(count);
// 	}
// 	close(fd);
// 	map->file = malloc(sizeof(char *) * (map->rows + 1));
// 	if (!map->file)
// 		return (-1);
// 	fd = open(path, O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	line = NULL;
// 	while ((line = get_next_line(fd)) && *line != '\0')
// 	{
// 		map->file[i] = ft_strdup(line);
// 		i++;
// 		free(line);
// 	}
// 	// Print the map
// 	// int j = 0;
// 	// while (j < map->rows)
// 	// {
// 	//     printf("map[%d] = %s\n", j, map->file[j]);
// 	//     j++;
// 	// }
// 	return (1);
// }
