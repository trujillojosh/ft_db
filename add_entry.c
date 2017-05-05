/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:38:01 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/04 18:13:18 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_list	*new_entry_field(t_list	*attr, int id)
{
	t_list	*head;
	t_list	*res;
	char	*tmp;

	tmp = ft_itoa(id);
	res = ft_lstnew(tmp, strlen(tmp));
	head = res;
	attr = attr->next;
	free(tmp);
	while (attr)
	{
		printf("\nPlease enter value for %s then press enter.\n", attr->content);
		get_next_line(0, &tmp);
		res->next = ft_lstnew(tmp, sizeof(tmp));
		res = res->next;
		attr = attr->next;
		free(tmp);
	}
	return (head);
}

char	***add_entry(t_list *attr, char ***data)
{
	t_list	*entry;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data[0][j] != NULL)
		j++;
	entry = new_entry_field(attr, j);
	while (entry)
	{
		data[i][j] = entry->content;
		entry = entry->next;
		i++;
	}
	print_entry(j, data, attr);
	return (data);
}
