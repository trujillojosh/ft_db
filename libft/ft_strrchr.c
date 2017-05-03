/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:54:17 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/01 13:21:53 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char		*r;
	unsigned char	a;
	int				len;

	a = (unsigned char)c;
	r = 0;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == a)
			return ((char *)&str[len]);
		len--;
	}
	return (0);
}
