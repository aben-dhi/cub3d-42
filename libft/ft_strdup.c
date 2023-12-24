/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:37:37 by aben-dhi          #+#    #+#             */
/*   Updated: 2022/10/16 15:46:57 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*d1;
	char	*d2;

	i = 0;
	d2 = ((d1 = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)));
	if (d1 == 0)
		return (0);
	while (s1[i])
	{
		d1[i] = s1[i];
		i++;
	}
	d1[i] = '\0';
	return (d1);
}
