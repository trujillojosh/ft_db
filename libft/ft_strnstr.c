/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:41:29 by jtrujill          #+#    #+#             */
/*   Updated: 2016/11/30 20:41:42 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s, const char *tf, size_t n)
{
	char	*str;
	char	*to_find;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	str = (char *)s;
	to_find = (char *)tf;
	if (to_find[i] == '\0' || ft_strcmp(s, tf) == 0)
		return (str);
	while (str[i] != '\0' && i < n)
	{
		while (str[i + a] == to_find[a])
		{
			if (to_find[a + 1] == '\0' && ((i + a) < n))
				return (&str[i]);
			a++;
		}
		a = 0;
		i++;
	}
	return (NULL);
}
