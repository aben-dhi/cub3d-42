/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:05:16 by htouil            #+#    #+#             */
/*   Updated: 2024/01/01 21:34:02 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_map_errors(t_map *map)
{
	if (check_map_frame0(map) == 0 || check_map_frame1(map) == 0
		|| check_map_frame2(map) == 0)
	{
		ft_putstr_fd("Error\nThe map is not fully surrounded with walls!\n", 2);
		free_data(map);
		exit(1);
	}
	if (check_map_content(map) == 0)
	{
		ft_putstr_fd("Error\nThe map doesn't have all the contents needed!\n", 2);
		free_data(map);
		exit(1);
	}
	if (check_map_player(map) == 0)
	{
		ft_putstr_fd("Error\nThe map doesn't have one and one player only!\n", 2);
		free_data(map);
		exit(1);
	}
}
