/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:55:32 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/05 15:34:15 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		attr_select(t_list *attr)
{
	int 	i;
	t_list	*head;
	char	*tmp;

	i = 1;
	head = attr;
	printf("\nWhich attribute would you like to modify?\n");
	while (attr)
	{
		printf("[%d] %s\n", i, attr->content);
		i++;
		attr = attr->next;
	}
	get_next_line(0, &tmp);
	i = ft_atoi(tmp) - 1;
	free(tmp);
	if (i >= ft_lstsize(head))
		return (-1);
	return (i);
}

char	***delete_entry(t_list *attr, char ***data, int entry)
{
	char	***res;
	int 	i;
	int		j;
	int 	k;

	i = 0;
	j = 0;
	k = 0;
	res = create_db(ft_lstsize(attr), attr);
	while (j < entry)
	{
		i = 0;
		while (i < ft_lstsize(attr))
		{
			res[i][j] = data[i][j];
			i++;
		}
		j++;
	}
	k = j + 1;
	while (data[0][k] != NULL)
	{
		i = 0;
		while (i < ft_lstsize(attr))
		{
			if (i == 0)
				res[i][j] = data[i][j];
			else
				res[i][j] = data[i][k];
			i++;
		}
		j++;
		k++;
	}
	return (res);
}

char	***modify_entry(t_list *attr, char ***data, int entry)
{
	int		choice;
	char	*tmp;
	
	choice = attr_select(attr);
	printf("\nWhat would you like to change the value to?\n");
	get_next_line(0, &tmp);
	data[choice][entry] = tmp;
	free(tmp);
	return (data);
}

char	***manage_entry(t_list *attr, char ***data, int entry)
{
	int		i;
	char	*tmp;
	print_entry(entry, data, attr);
	printf("\nPlease select an option from below\n");
	printf("[%d] Modify | [%d] Delete | [%d] Return to Main Menu\n", 1, 2, 3);
	get_next_line(0, &tmp);
	i = atoi(tmp);
	free(tmp);
	if (i == 2)
		return (delete_entry(attr, data, entry));
	else if (i == 1)
		return (modify_entry(attr, data, entry));
	else
		return (data);
}

