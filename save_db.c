/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 23:41:04 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/02 00:10:14 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*new_filename(char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = strdup("saves/");
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	tmp = ft_strjoin(tmp2, ".txt");
	free(tmp2);
	return (tmp);
}

void	save_data(FILE *fp, t_list *attr, char ***data)
{
	int		i;
	int		j;
	t_list	*head;

	i = 0;
	j = 0;
	head = attr;
	while (attr)
	{
		fprintf(fp, "%s", (char *)attr->content);
		attr = attr->next;
		if (attr)
			fprintf(fp, "%c", ',');
	}
	attr = head;
	fprintf(fp, "%c", '\n');
	while (data[0][j] != NULL)
	{
		i = 0;
		while (i < ft_lstsize(attr))
		{
			fprintf(fp, "%s", data[i][j]);
			if ((i + 1) < ft_lstsize(attr))
				fprintf(fp, "%c", ',');
			i++;
		}
		j++;
		fprintf(fp, "%c", '\n');
	}
}

void	save_db(t_list *attr, char ***data)
{
	char	str[25];
	char	*file;
	FILE	*fp;

	memset(str, '\0', sizeof(str));
	printf("\n%s", "Warning, if save already exists it will be overwritten.");
	printf("\n%s", "Please enter save name: ");
	fgets(str, sizeof(str), stdin);
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	file = new_filename(str);
	fp = fopen(file, "w+");
	save_data(fp, attr, data);
	fclose(fp);
	free(file);
}
