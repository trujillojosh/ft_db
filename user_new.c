/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 22:22:26 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/01 22:22:33 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_list	*get_attr(void) //gets initial attributes from user
{
	t_list	*head;
	t_list	*curr;
	char	*str;
	int 	i;

	i = 0;
	head = ft_lstnew("ID", 3);
	curr = head;
	printf("\n%s\n", "Please enter each attribute name, followed by enter.");
	printf("%s\n", "Once finished, press enter again or write 'finished'.");
	while (1)
	{
		printf("\n%s\n", "Enter Attribute name below:");
		get_next_line(0, &str);
		if ((strcmp(str, "finished") == 0) || (strlen(str) == 0))
			break ;
		curr->next = ft_lstnew(str, sizeof(str));
		curr = curr->next;
		free(str);
		i++;
	}
	return (head);
}

int 	another_entry(void) //if user would like to make another entry
{
	char	*str;

	printf("\n%s\n", "Would you like to make another entry(yes/no):");
	get_next_line(0, &str);
	if (str[0] == 'y')
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

char 	*fill_data(char *content) //fills each attribute based on user response
{
	char	*str;
	char	*res;

	printf("\nPlease enter value for %s:\n", content);
	get_next_line(0, &str);
	return (str);
}

char	***user_populate(int size, t_list *attr) //allows user to create new data inside a new 3d array
{
	char	***data;
	t_list	*head;
	int 	i;
	int 	id;

	id = 0;
	i = 1;
	data = create_db(size, attr);
	printf("\n%s\n", "Now let's move on the the first entry.");
	while (1)
	{
		head = attr;
		head = head->next;
		data[0][id] = strdup(ft_itoa(id));
		i = 1;
		while (i < size)
		{
			data[i][id] = fill_data(head->content);
			i++;
			head = head->next;
		}
		if (another_entry() == 0)
			break ;
		id++;
	}
	return (data);
}
