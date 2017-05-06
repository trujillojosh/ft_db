/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_db.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:09:50 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/05 14:19:27 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		attr_option(t_list *attr)
{
	int 	i;
	t_list	*head;
	char	*tmp;

	i = 1;
	head = attr;
	printf("\nWhich attribute would you like to search by?\n");
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

int 	selection_index(t_list *res, int choice)
{
	if (choice >= ft_lstsize(res))
		return (-1);
	while (choice > 0)
	{
		res = res->next;
		choice--;
	}
	return (atoi(res->content));
}

int		make_selection(t_list *res, char ***data, t_list *attr)
{
	int 	choice;
	int		tmp;
	char	*tmp2;
	t_list	*head;
	
	choice = 1;
	tmp = 0;
	head = res;
	printf("\nPlease select which result you would like to access.");
	while (res)
	{
		tmp = atoi(res->content);
		print_entry_line(choice, tmp, data, attr);
		res = res->next;
		choice++;
	}
	printf("%c", '\n');
	get_next_line(0, &tmp2);
	tmp = atoi(tmp2);
	free(tmp2);
	tmp--;
	tmp = selection_index(head, tmp);
	printf("\n\ntmp is --> %d\n\n", tmp);
	return (tmp);
}

int 	search_db(t_list *attr, char ***data)
{
	int		search;
	int		j;
	t_list	*res;
	t_list	*head;
	char	*tmp;

	j = 0;
	search = attr_option(attr);
	printf("\nWhat would you like to search for?\n");
	get_next_line(0, &tmp);
	head = ft_lstnew(tmp, strlen(tmp));
	res = head;
	while (data[search][j] != NULL)
	{
		if (strcmp(tmp, data[search][j])== 0)
		{
			res->next = ft_lstnew(ft_itoa(j), strlen(ft_itoa(j)));
			res = res->next;
		}
		j++;
	}
	if (ft_lstsize(head) <= 1)
	{
		free(tmp);
		return (-1);
	}
	else
	{
		head = head->next;
		search = make_selection(head, data, attr);
		free(tmp);
		return (search);
	}
}
