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
	size_t	j;
	size_t	len;
	size_t	i;
	size_t	k;
	char 	*temp;

	i = 0;
	if ((ft_char_count(str, ',')) > 0)
		i += 2;
	j = (ft_char_count(str, '\"')) + (strlen(str));
	len  = i + j;
	k = 0;
	if (!(temp = ft_strnew(len)))
		return (NULL);
	if (i > 0)
	{
		k++;
		temp[0] = '\"';
	}
	while (*str)
	{
		if (*str == '\"')
		{
			temp[k] = '\"';
			temp[k + 1] = '\"';
			k++;
		}
		temp[k] = *str;
		k++;
		str++;
	}
	if (i > 0)
		temp[len - 1] = '\"';
	temp[len] = '\0';
	return (temp);
}

char	*csv_std(char *str)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	i = strlen(str);
	res = ft_strnew(i);
	while (*str != '\0')
	{
		if ((ft_char_count(str, ',') > 0) && (j == 0))
		{
			if (*str != '\"')
			{
				free(res);
				return (NULL);
			}
			i = -1;
			str++;
		}
		if ((*(str + 1) == '\0') && (*str == '\"'))
			break ;
		if ((*str == '\"') && (*(str + 1) == '\"'))
			if (i == -1)
				str++;
		res[j++] = *str;
		str++;
	}
	return (res);
}

t_list	*split_csv(char *str)
{
	t_list *head;
	t_list *curr;
	int 	i;
	char 	*tmp;
	int 	count;

	i = 0;
	count = 0;
	head = ft_lstnew(str, strlen(str));
	curr = head;
	while (*str != '\0')
	{
		if ((*str != '\"') && (*str != '\0'))
		{
			i = ft_until(str, ',');
			tmp = ft_strnew(i);
			tmp = ft_strncpy(tmp, str, i);
			while ((*str != ',') && (*str != '\0'))
				str++;
			if (*str == ',')
				str++;
		}
		else if (*str == '\"')
		{
			count = 1;
			i = 1;
			while ((count > 0) && (str[i] != '\0'))
			{
				if (str[i] == '\"')
				{
					if (str[i + 1] == '\"')
						i++;
					else
						count = 0;
					i++;
				}
				else
					i++;
			}
			tmp = ft_strnew(i);
			tmp = ft_strncpy(tmp, str, i);
			while (i > 0)
			{
				str++;
				i--;
			}
			if (*str == ',')
				str++;
		}
		curr->next = ft_lstnew(tmp, strlen(tmp));
		free(tmp);
		curr = curr->next;
	}
	head = head->next;
	return (head);
}
