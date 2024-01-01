/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:02:08 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/26 22:13:00 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*savenorth(t_map *map, int i, int j)
{
	if (map->file[i][j] == 'N' && map->file[i][j + 1] == 'O')
	{
		return (ft_substr(map->file[i], j + 2, ft_strlen(map->file[i])));
	}
	return (NULL);
}

char	*savesouth(t_map *map, int i, int j)
{
	if (map->file[i][j] == 'S' && map->file[i][j + 1] == 'O')
	{
		map->so = ft_substr(map->file[i], j + 2, ft_strlen(map->file[i]));
		return (map->so);
	}
	return (NULL);
}

char	*saveeast(t_map *map, int i, int j)
{
	if (map->file[i][j] == 'E' && map->file[i][j + 1] == 'A')
	{
		map->ea = ft_substr(map->file[i], j + 2, ft_strlen(map->file[i]));
		return (map->ea);
	}
	return (NULL);
}

char	*savewest(t_map *map, int i, int j)
{
	if (map->file[i][j] == 'W' && map->file[i][j + 1] == 'E')
	{
		map->we = ft_substr(map->file[i], j + 2, ft_strlen(map->file[i]));
		return (map->we);
	}
	return (NULL);
}

void	save_dir(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows && map->file[i])
	{
		j = 0;
		while (map->file[i][j] != '\0')
		{
			if (map->file[i][j] == 'N' && map->file[i][j + 1] == 'O')
				map->no = savenorth(map, i, j);

			if (map->file[i][j] == 'S' && map->file[i][j + 1] == 'O')
				map->so = savesouth(map, i, j);

			if (map->file[i][j] == 'E' && map->file[i][j + 1] == 'A')
				map->ea = saveeast(map, i, j);

			if (map->file[i][j] == 'W' && map->file[i][j + 1] == 'E')
				map->we = savewest(map, i, j);
			j++;
		}
		i++;
	}
}
