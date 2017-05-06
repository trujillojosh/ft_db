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

t_list *split_csv(char *str)
{
	t_list	*head;
	t_list	*curr;
	char 	*tmp;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	curr = ft_lstnew(str, strlen(str));
	head = curr;
	while (*str != '\0')
	{
		if (*str != '\"')
		{
			i = ft_until(str, ',');
			tmp = ft_strnew(i);
			tmp = strncpy(tmp, str, i);
			while ((*str != ',') && (*str != '\0'))
				str++;
		}
		else
		{
			if (strlen(str) == 1)
				return (NULL);
			str++;
			i = ft_until(str, '\"');
			tmp = ft_strnew(i);
			tmp = strncpy(tmp, str, i);
			while ((*str != '\"') && (*str != '\0'))
				str++;
			if (*str == '\"')
				str++;
		}
		if (*str == ',')
			str++;
		curr->next = ft_lstnew(tmp, strlen(tmp));
		free(tmp);
		curr = curr->next;
	}
	head = head->next;
	return (head);
}
