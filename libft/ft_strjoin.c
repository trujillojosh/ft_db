/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:04:47 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/23 16:10:49 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*o;
	char	*t;
	char	*n;
	int		i;

	i = 0;
	o = (char *)s1;
	t = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	if (!(n = (char *)malloc(sizeof(char) * (ft_strlen(o) + ft_strlen(t) + 1))))
		return (NULL);
	while (*o)
	{
		n[i] = *o;
		i++;
		o++;
	}
	while (*t)
	{
		n[i++] = *t;
		t++;
	}
	n[i] = '\0';
	return (n);
}
