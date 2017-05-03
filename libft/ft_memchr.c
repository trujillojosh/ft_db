/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:16:08 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/01 17:24:37 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	a;

	s = (unsigned char *)str;
	a = (unsigned char)c;
	while (n > 0)
	{
		if (*s == a)
			return (s);
		s++;
		n--;
	}
	return (NULL);
}
