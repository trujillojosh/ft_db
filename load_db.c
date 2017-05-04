/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:18:46 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/02 23:09:44 by jtrujill         ###   ########.fr       */
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

t_list	*read_attr(FILE *fp, int mode) //take mode out, tomorrow
{
	static t_list	*head;
	t_list	*curr;
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if (mode == 1)
		return (head);
	get_next_line(fileno(fp), &line);
	head = ft_lstnew(line, strlen(line));
	curr = head;
	while (*line != '\0')
	{
		if (*line == ',')
			line++;
		i = ft_until((const char *)line, ',');
		tmp = ft_strnew(i);
		tmp = ft_strncpy(tmp, line, i);
		curr->next = ft_lstnew(tmp, strlen(tmp));
		curr = curr->next;
		free(tmp);
		while ((*line != ',') && (*line != '\0'))
			line++;
	}
	head = head->next;
	return (head);
}

char	***file_data(FILE *fp, t_list *attr)
{
	char	***res;
	t_list	*data;
	char	*tmp;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	res = create_db(ft_lstsize(attr), attr);
	while (1)
	{
		i = 0;
		if (!(get_next_line(fileno(fp), &tmp)))
			break ;
		data = split_csv(tmp);
		free(tmp);
		while (i < ft_lstsize(attr))
		{
			res[i][j] = csv_std(data->content);
			data = data->next;
			i++;
		}
		j++;
	}
	return(res);
}
char	***read_csv(char *save)
{
	char	***data;
	t_list	*attr;
	FILE	*fp;

	fp = fopen(save, "r");
	attr = read_attr(fp, 0);
	data = file_data(fp, attr);
	fclose(fp);
	return (data);
}

// void	read_csv(char *save)
// {
// 	t_list	*attr;
// 	FILE	*fp;

// 	printf("\nsave is --> %s", save);
// 	fp = fopen(save, "r");
// 	if (fp == NULL)
// 		printf("\nerror, fp is bad");
// 	printf("%c", '\n');
// 	attr = read_attr(fp);
// 	fclose(fp);
// 	ft_print_list(attr);
// }