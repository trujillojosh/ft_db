/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:09:05 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/07 20:21:41 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*t;
	unsigned char		nc;
	unsigned char		*s;
	unsigned int		i;

	i = 0;
	nc = (unsigned char)c;
	t = (unsigned char *)src;
	s = (unsigned char *)dest;
	while (i < n)
	{
		*s = *t;
		if (*t == nc)
		{
			s++;
			return (s);
		}
		s++;
		t++;
		i++;
	}
	return (NULL);
}
