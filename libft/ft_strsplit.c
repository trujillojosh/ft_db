/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:16:02 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/07 13:16:10 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * ft_cd_freq(s, c))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			res[i] = (char *)malloc(sizeof(char) * ((ft_until(s, c)) + 1));
			while (ft_until(s, c) > 0)
				res[i][j++] = *s++;
			res[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
