/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:55:14 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/01/05 20:21:00 by htouil           ###   ########.fr       */
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

char	*ft_datacpy(char *src)
{
	char	*dst;
	int		i;

	if (!src)
		return (NULL);
	src = src + 2;
	src = skip_spaces(src);
	dst = malloc((ft_strlen(src) - 1 + 1) * sizeof(char));
	if (!dst)
		exit(1);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	dst = ft_strtrim(dst, " ");
	return (dst);
}

char	*skip_spaces(char *str)
{
	while (*str && *str == ' ')
		str++;
	return (str);
}

int	avoid_spaces(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] && str[pos] == ' ')
		pos++;
	return (pos);
}

int	reverse_avoid_spaces(char *str)
{
	int	pos;

	pos = ft_strlen1(str) - 1;
	while (str[pos] && str[pos] == ' ')
		pos--;
	return (pos);
}

int	ft_strlcmp(char *s1, char *s2, int n)
{
	if ((ft_strncmp(s1, s2, n) == 0) && (*(s1 + n) == ' '))
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
		if (str[0] == '\0' || (str[i] != ' ' && str[i] != '\n'))
		{
			tmp = skip_spaces(str);
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
	char	*tmp;

	i = 0;
	while (lmap[i] && lmap[i + 1])
	{
		if (lmap[i] == '\n')
		{
			tmp = skip_spaces(&lmap[i + 1]);
			if (tmp[0] == '\n')
				return (1);
		}
		i++;
	}
	return (0);
}

void	display_dnl_error(char *lmap)
{
	if (check_double_nl(lmap) == 1)
	{
		ft_putstr_fd("Error\nThe map is not fully surrounded with walls!!!\n", 2);
		free(lmap);
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
