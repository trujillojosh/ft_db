/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:18:46 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/02 16:48:08 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_list	*curr_saves(void)
{
	t_list			*head;
	t_list			*curr;
	int				i;
	DIR				*dir;
	struct dirent	*ep;
	
	i = 0;
	dir = opendir("saves");
	if (dir == NULL)
		return (NULL);
	while ((ep = readdir(dir)))
	{
			if (i++ == 0)
			{
				head = ft_lstnew(ep->d_name, sizeof(ep->d_name));
				curr = head;
			}
			else
			{
				curr->next = ft_lstnew(ep->d_name, sizeof(ep->d_name));
				curr = curr->next;
			}
	}
	(void)closedir(dir);
	return (head);
}

void	save_options(t_list *save)
{
	int		i;

	i = 0;
	while (save)
	{
		i = strlen(save->content) - 4;
		printf("\ni is --> %d", i);
		if (i > 0)
			if (strcmp(&(save->content)[i], ".txt") == 0)
				printf("\nsuccess == %s", save->content);
		save = save->next;
	}
}