/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:52:26 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/02 11:04:21 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = ft_strlen(dest) + (ft_strlen(src));
	while (dest[i] != '\0' && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (ft_strlen(src) + i);
	while (*src != '\0')
	{
		if (n > 1)
		{
			dest[i] = *src;
			i++;
			n--;
		}
		src++;
	}
	dest[i] = '\0';
	return (k);
}
