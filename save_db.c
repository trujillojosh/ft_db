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

	// i = 0; made i = -1 down below 
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
		i = -1; //since we dont use it until now we can initialize to -1 and do ++1 to save lines
		while (++i < ft_lstsize(attr))
		{
			fprintf(fp, "%s", create_csv(data[i][j]));
			if ((i + 1) < ft_lstsize(attr))
				fprintf(fp, "%c", ',');
			// i++;
		}
		j++;
		fprintf(fp, "%c", '\n');
	}
}

void	save_db(t_list *attr, char ***data)
{
	char	*str;
	char	*file;
	FILE	*fp;

	printf("\n%s", "Warning, if save already exists it will be overwritten.");
	printf("\n%s\n", "Please enter save name below:");
	get_next_line(0, &str);
	file = new_filename(str);
	fp = fopen(file, "w+");
	save_data(fp, attr, data);
	fclose(fp);
	free(file);
	free(str);
}
