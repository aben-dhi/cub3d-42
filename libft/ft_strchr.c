/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:03:31 by aben-dhi          #+#    #+#             */
/*   Updated: 2022/10/05 15:22:19 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*b;
	int		i;

	i = 0;
	a = (char)c;
	b = (char *)s;
	while (b[i] != a)
	{
		if (b[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)b + i);
}
