/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 19:49:28 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/01 19:49:37 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char 	***create_db(int size, t_list *attr) //creates 3d array based on list of attributes
{
	char 	***res;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	res = (char ***)malloc(sizeof(char **) * (size + 1));
	while (attr)
	{
		res[i] = (char **)malloc(sizeof(char *) * 1001);
		j = 0;
		while (j < 1000)
		{
			res[i][j] = NULL;
			j++;
		}
		res[i][1000] = NULL;
		i++;
		attr = attr->next;
	}
	res[i] = NULL;
	return (res);
}
