/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:18:46 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/05 23:12:08 by jtrujill         ###   ########.fr       */
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

char	*save_options(t_list *save)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*input;

	i = 0;
	printf("\n%s", "The following saves exist:");
	while (save)
	{
		i = strlen(save->content) - 4;
		if (i > 0)
			if (strcmp(&(save->content)[i], ".txt") == 0)
			{
				((char *)save->content)[i] = '\0';
				printf("\n%s", save->content);
			}
		save = save->next;
	}
	printf("\n\n%s\n", "Which database would you like to load?");
	get_next_line(0, &input);
	tmp2 = ft_strjoin("saves/", input);
	tmp = ft_strjoin(tmp2, ".txt");
	free(tmp2);
	free(input);
	return (tmp);
}

t_list	*read_attr(FILE *fp, int mode)
{
	static t_list	*head;
	t_list			*lst;
	char			*line;
	int				i;

	i = 0;
	if (mode == 1)
	{
		if (head != NULL)
			return (head);
		return (NULL);
	}
	if (!(get_next_line(fileno(fp), &line)))
		return (NULL);
	head = ft_lstnew(line, strlen(line));
	lst = split_csv(line);
	free(line);
	head = lst;
	return (head);
}

char	***file_data(FILE *fp, t_list *attr)
{
	char	***res;
	t_list	*data;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (get_next_line(fileno(fp), &tmp))
	{
		free(tmp);
		i++;
	}
	res = create_db(ft_lstsize(attr), attr, (i + 250));
	i = 0;
	rewind(fp);
	get_next_line(fileno(fp), &tmp);
	free(tmp);
	while (1)
	{
		i = 0;
		if (!(get_next_line(fileno(fp), &tmp)))
			break ;
		data = split_csv(tmp);
		free(tmp);
		while (i < ft_lstsize(attr))
		{
			res[i][j] = data->content;
			data = data->next;
			i++;
		}
		j++;
	}
	return (res);
}

char	***read_csv(char *save)
{
	char	***data;
	t_list	*attr;
	FILE	*fp;

	fp = fopen(save, "r");
	if (fp == NULL)
		return (NULL);
	attr = read_attr(fp, 0);
	data = file_data(fp, attr);
	fclose(fp);
	return (data);
}
