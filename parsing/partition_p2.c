/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:28 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/26 22:13:00 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_f(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'F')
		{
			map->f = ft_substr(line, i + 1, ft_strlen(line));
			return (map->f);
		}
		i++;
	}
	return (0);
}

char	*get_c(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'C')
		{
			map->c = ft_substr(line, i + 1, ft_strlen(line));
			return (map->c);
		}
		i++;
	}
	return (0);
}

int	save_fc(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	// int max = 0; 
	while (i < map->rows && map->file[i])
	{
		j = 0;
		while (map->file[i][j] != '\0')
		{
			// max = get_f(map->file[i], map);
			// if (max < get_c(map->file[i], map))
			// 	max = get_c(map->file[i], map);
			get_f(map->file[i], map);
			get_c(map->file[i], map);
			j++;
		}
		if (map->c && map->f)
			return (i);
		i++;
	}
	return (i);
}
//we need to add a spaces checker
// int	last_pos(t_map *map)
// {
// 	int i = 0;
// 	while (i < map->rows && map->file[i])
// 	{
// 		int j = 0;
// 		while (map->file[i][j] != '\0')
// 		{
// 			if (!ft_isspace(map->file[i][j]))
// 			{
// 				if (map->file[i][j] == '1')
// 					return (i);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

