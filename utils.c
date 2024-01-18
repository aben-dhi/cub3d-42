/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:55:14 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/01/16 20:05:09 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_realloc(void *ptr, int size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, ptr, size);
	free(ptr);
	return (res);
}

char	*ft_datacpy(char *src, int n)
{
	char	*dst;
	char	*tmp;
	int		i;
	int		j;

	if (!src)
		return (NULL);
	// src = src + 2;
	i = n;
	while (src[i] == ' ' || src[i] == '\t') //hmm???
		i++;
	tmp = malloc((ft_strlen1(src) - i + 1) * sizeof(char));
	if (!tmp)
		exit(1);
	j = 0;
	while (src[i] != '\0' && src[i] != '\n')
	{
		tmp[j] = src[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	// src = src - 2; //hmm???
	dst = ft_strtrim(tmp, "\n ");
	free(tmp);
	return (dst);
}

char	*skip_spaces(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

int	avoid_spaces(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] && (str[pos] == ' ' || str[pos] == '\t'))
		pos++;
	return (pos);
}

int	reverse_avoid_spaces(char *str)
{
	int	pos;

	pos = ft_strlen1(str) - 1;
	while (str[pos] && (str[pos] == ' ' || str[pos] == '\t'))
		pos--;
	return (pos);
}

int	ft_strlcmp(char *s1, char *s2, int n)
{
	if (ft_strncmp(s1, s2, n) == 0)
		return (0);
	return (1);
}

int	check_empty_spaces(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[0] == '\0' || (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			tmp = str;
			tmp = skip_spaces(tmp);
			if (ft_strlcmp(tmp, "NO", 2) == 0 || ft_strlcmp(tmp, "SO", 2) == 0
				|| ft_strlcmp(tmp, "WE", 2) == 0
				|| ft_strlcmp(tmp, "EA", 2) == 0
				|| ft_strlcmp(tmp, "F", 1) == 0 || ft_strlcmp(tmp, "C", 1) == 0)
				return (2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_double_nl(char *lmap)
{
	int		i;

	i = 0;
	while (lmap[i] != '\0')
	{
		if (lmap[i] == '\n')
		{
			i++;
			while (lmap[i] != '\0' && (lmap[i] == ' ' || lmap[i] == '\t'))
				i++;
			if (lmap[i] == '\0')
				return (0);
			else if (lmap[i] == '\n')
			{
				i++;
				while (lmap[i] != '\0' && (lmap[i] == ' ' || lmap[i] == '\t'))
					i++;
				if (lmap[i] == '\0' || lmap[i] == '\n')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

void	display_dnl_error(char *lmap)
{
	if (check_double_nl(lmap) == 1)
	{
		ft_putstr_fd("Error\nThe map is invalid!\n", 2);
		free(lmap);
		// while (1);
		// system("leaks cub3D");
		exit(1);
	}
}

void	free_data(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->rows)
	{
		if (map->map[j])
			free(map->map[j]);
		j++;
	}
	if (map->map)
		free(map->map);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->f)
		free(map->f);
	if (map->c)
		free(map->c);
	if (map->columns)
		free(map->columns);
	free(map);
}

void	free_tmp(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j])
			free(str[j]);
		j++;
	}
	free(str);
}
