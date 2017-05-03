/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:53:21 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/01 17:12:06 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s >= d)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		d = (d + n) - 1;
		s = (s + n) - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	return (dest);
}
