/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:56:17 by htouil            #+#    #+#             */
/*   Updated: 2024/01/05 20:13:59 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_1(char **tmp, t_map *map)
{
	int		koma;
	int		i;
	int		j;

	i = -1;
	koma = 0;
	while (map->f[++i])
	{
		if (map->f[i] == ',')
			koma++;
	}
	j = 0;
	while (tmp[j])
		j++;
	if (j != 3 || koma != 2)
		return (0);
	return (1);
}

int	check_2(char **tmp)
{
	int	i;
	int	j;

	j = -1;
	while (tmp[++j])
	{
		i = -1;
		while (tmp[j][++i])
		{
			if (ft_isdigit(tmp[j][i]) == 0)
				return (0);
		}
		if (ft_atoi(tmp[j]) < 0 || ft_atoi(tmp[j]) > 255)
			return (0);
	}
	return (1);
}

int	check_rgb(t_map *map)
{
	char	**tmp;

	tmp = ft_split(map->f, ',');
	if (check_1(tmp, map) == 0 || check_2(tmp) == 0)
		return (free_tmp(tmp), 0);
	free_tmp(tmp);
	tmp = ft_split(map->c, ',');
	if (check_1(tmp, map) == 0 || check_2(tmp) == 0)
		return (free_tmp(tmp), 0);
	free_tmp(tmp);
	return (1);
}
