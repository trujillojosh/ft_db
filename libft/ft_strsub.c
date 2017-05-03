/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:41:57 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/03 19:37:03 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*str;
	char				*res;
	unsigned int		i;
	unsigned char		nc;

	i = 0;
	str = (char *)s;
	nc = (unsigned char)start;
	if (!s)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0)
	{
		res[i] = str[nc];
		i++;
		nc++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
