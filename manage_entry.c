/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:55:32 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/05 23:08:39 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		attr_select(t_list *attr)
{
	int		i;
	t_list	*head;
	char	*tmp;

	i = 1;
	attr = attr->next;
	head = attr;
	printf("\nWhich attribute would you like to modify?\n");
	while (attr)
	{
		printf("[%d] %s\n", i, attr->content);
		i++;
		attr = attr->next;
	}
	get_next_line(0, &tmp);
	i = atoi(tmp);
	free(tmp);
	if (i >= ft_lstsize(head))
		return (-1);
	return (i);
}

void	delete_entry(t_list *attr, char ****data, int entry)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	while (j < entry)
		j++;
	k = j + 1;
	while ((*data)[0][k] != NULL)
	{
		i = 1;
		while (i < ft_lstsize(attr))
		{
			free((*data)[i][j]);
			(*data)[i][j] = strdup((*data)[i][k]);
			i++;
		}
		j++;
		k++;
	}
	i = 0;
	k--;
	while (i < ft_lstsize(attr))
	{
		free((*data)[i][k]);
		(*data)[i][k] = NULL;
		i++;
	}
}

void	modify_entry(t_list *attr, char ****data, int entry)
{
	int		choice;
	char	*tmp;

	choice = attr_select(attr);
	if (choice <= 0)
	{
		printf("\nInvalid option\n");
		return ;
	}
	printf("\nWhat would you like to change the value to?\n");
	get_next_line(0, &tmp);
	if ((ft_char_count(tmp, '\"') > 0) || (ft_char_count(tmp, '\n')))
	{
		printf("\nQuotation marks and newlines are not valid characters, please try again");
		free(tmp);
		modify_entry(attr, data, entry);
		return ;
	}
	free((*data)[choice][entry]);
	(*data)[choice][entry] = strdup(tmp);
	free(tmp);
}

void	manage_entry(t_list *attr, char ****data, int entry)
{
	int		i;
	char	*tmp;

	print_entry(entry, *data, attr);
	printf("\nPlease select an option from below\n");
	printf("[%d] Modify | [%d] Delete | [%d] Return to Main Menu\n", 1, 2, 3);
	get_next_line(0, &tmp);
	i = atoi(tmp);
	free(tmp);
	if (i == 2)
		delete_entry(attr, data, entry);
	else if (i == 1)
		modify_entry(attr, data, entry);
}
