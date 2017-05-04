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
	char	input[100];

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
	printf("\n\n%s", "Which database would you like to load: ");
	fgets(input, sizeof(input), stdin);
	if (input[strlen(input) - 1] == '\n')
		input[strlen(input) - 1] = '\0';
	tmp2 = ft_strjoin("saves/", input);
	tmp = ft_strjoin(tmp2, ".txt");
	free(tmp2);
	return (tmp);
}

// char	*read_entry(FILE *fp)
// {
// 	static	char	*str;
// }

t_list	*read_attr(FILE *fp)
{
	t_list	*head;
	t_list	*curr;
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
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
// char	***read_csv(char *save)
// {
// 	char	***data;
// 	t_list	*attr;
// 	FILE	*fp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	fp = fopen(save, r+);
// 	attr = read_attr(FILE *fp)

void	read_csv(char *save)
{
	t_list	*attr;
	FILE	*fp;

	printf("\nsave is --> %s", save);
	fp = fopen(save, "r");
	if (fp == NULL)
		printf("\nerror, fp is bad");
	printf("%c", '\n');
	attr = read_attr(fp);
	fclose(fp);
	ft_print_list(attr);
}