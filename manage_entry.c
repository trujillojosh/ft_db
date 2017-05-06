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
	i = atoi(tmp) - 1;
	free(tmp);
	if (i >= ft_lstsize(head))
		return (-1);
	return (i);
}

void	delete_entry(t_list *attr, char ****data, int entry)
{
	int 	i;
	int 	j;
	int 	k;
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
	printf("\n\nchoice is --> %d\n\n", choice);
	if (choice == 0)
	{
		printf("\nCannot modify ID Value");
		return ;
	}
	if (choice < 0)
	{
		return ;
	}
	printf("\nWhat would you like to change the value to?\n");
	get_next_line(0, &tmp);
	// printf("\n\ntmp is --> %s\n\n", tmp);
	// printf("\n\nchoice is %d\nentry is %d\ndata is %s\n\n", choice, entry, (*data)[choice][entry]);
	free((*data)[choice][entry]);
	(*data)[choice][entry] = strdup(tmp);
	// printf("\n\nchoice after is %d\nentry is %d\ndata is %s\n\n", choice, entry, (*data)[choice][entry]);
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
	{
		modify_entry(attr, data, entry);
		printf("\n in manage entry after modify %s\n", (*data)[1][entry]);
	}
}

