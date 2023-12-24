/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:55:14 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/01 18:58:13 by aben-dhi         ###   ########.fr       */
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
