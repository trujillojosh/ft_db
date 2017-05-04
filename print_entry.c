/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:40:54 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/03 17:49:53 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	print_entry(int j, char ***data, t_list *attr)
{
	int		i;
	int		k;

	i = 0;
	k = ft_lstsize(attr);
	while (i < k)
	{
		printf("\n%s: %s", attr->content, data[i][j]);
		i++;
		attr = attr->next;
	}
}
