/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csv_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:25:58 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/05 14:34:27 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char 	*create_csv(char *str)
{
	char 	*ret;
	int 	i;

	i = 0;
	if (ft_char_count(str, ',') <= 0)
		return (str);
	ret = ft_strnew(strlen(str) + 2);
	ret[i] = '\"';
	i++;
	while (*str != '\0')
	{
		ret[i] = *str;
		i++;
		str++;
	}
	ret[i] = '\"';
	return (ret);
}

static void		help_split(char **str, int mode)
{
	if (mode == 0)
	{
		while ((**str != ',') && (**str != '\0'))
			(*str)++;
	}
	else
	{
		while ((**str != '\"') && (**str != '\0'))
			(*str)++;
		if (**str == '\"')
			(*str)++;
	}
	if (**str == ',')
		(*str)++;
}

static char 	*help_split2(char **str, int mode)
{
	int 	i;
	char 	*tmp;

	i = 0;
	if (mode == 0)
		i = ft_until(*str, ',');
	else
	{
		if (strlen(*str) <= 1)
			return (NULL);
		(*str)++;
		i = ft_until(*str, '\"');
	}
	tmp = ft_strnew(i);
	tmp = strncpy(tmp, *str, i);
	return (tmp);
}

t_list *split_csv(char *str)
{
	t_list	*head;
	t_list	*curr;
	char 	*tmp;

	curr = ft_lstnew(str, strlen(str));
	head = curr;
	while (*str != '\0')
	{
		if (*str != '\"')
		{
			tmp = help_split2(&str, 0);
			help_split(&str, 0);
		}
		else
		{
			if (!(tmp = help_split2(&str, 1)))
				return (NULL);
			help_split(&str, 1);
		}
		curr->next = ft_lstnew(tmp, strlen(tmp));
		free(tmp);
		curr = curr->next;
	}
	head = head->next;
	return (head);
}
