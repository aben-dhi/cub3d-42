/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:32:06 by htouil            #+#    #+#             */
/*   Updated: 2024/01/03 17:54:18 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	associate_infos(char *line, t_map *map)
{
	char	*tmp;

	tmp = skip_spaces(line);
	if (ft_strncmp(tmp, "NO", 2) == 0)
		map->no = ft_datacpy(tmp);
	else if (ft_strncmp(tmp, "SO", 2) == 0)
		map->so = ft_datacpy(tmp);
	else if (ft_strncmp(tmp, "WE", 2) == 0)
		map->we = ft_datacpy(tmp);
	else if (ft_strncmp(tmp, "EA", 2) == 0)
		map->ea = ft_datacpy(tmp);
	else if (ft_strncmp(tmp, "F", 1) == 0)
		map->f = ft_datacpy(tmp);
	else if (ft_strncmp(tmp, "C", 1) == 0)
	{
		map->c = ft_datacpy(tmp);
		return (1);
	}
	return (0);
}

int	get_map_matrix(int fd, char *line, t_map *map)
{
	char	*map_str;

	map_str = ft_calloc(1, 1);
	if (!map_str)
		return (-1);
	while (1)
	{
		map_str = ft_strjoin(map_str, line);
		map->rows++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	display_dnl_error(map_str);
	map->map = ft_split(map_str, '\n');
	if (check_empty_spaces(map->map[map->rows - 1]) == 0)
	{
		free(map->map[map->rows - 1]);
		map->rows--;
	}
	free(map_str);
	close(fd);
	return (0);
}

// void	read_map_helper(int flag, char *line)
// {
	
// }

void	read_map(int fd, t_map *map)
{
	int		flag;
	char	*line;

	flag = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error\nFile is empty!\n", 2);
		exit (1);
	}
	while (1)
	{
		if (!line)
		{
			ft_putstr_fd("Error\nFile incomplet!\n", 2);
			free(line);
			exit(1);
		}
		if (flag == 1 && check_empty_spaces(line) == 1)
			break ;
		if (flag == 0 && check_empty_spaces(line) == 1)
		{
			ft_putstr_fd("Error\nInvalid file content!\n", 2);
			free(line);
			exit(1);
		}
		if (check_empty_spaces(line) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		// printf("salam: %s\n", line);
		flag = associate_infos(line, map);
		free(line);
		line = get_next_line(fd);
	}
	get_map_matrix(fd, line, map);
}
