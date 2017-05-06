/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 19:49:28 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/05 23:24:02 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	***create_db(int size, t_list *attr, int k)
{
	char	***res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char ***)malloc(sizeof(char **) * (size + 1));
	while (attr)
	{
		res[i] = (char **)malloc(sizeof(char *) * (k + 1));
		j = 0;
		while (j < k)
		{
			res[i][j] = NULL;
			j++;
		}
		res[i][k] = NULL;
		i++;
		attr = attr->next;
	}
	res[i] = NULL;
	return (res);
}
