/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:38:47 by dcastro-          #+#    #+#             */
/*   Updated: 2017/05/05 15:38:51 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	***strdup_db(t_list *attr, char ***data, int s)
{
	char	***temp;
	size_t	i;
	size_t	j;

	temp = create_db(ft_lstsize(attr), attr);
	i = -1;
	j = -1;
	while (++j < s)
	{
		i = -1;
		while (++i < ft_lstsize(attr))
			temp[i][j] = strdup(data[i][j]);
	}
	return (temp);
}

static	void	free_copy(char ***strdup_copy, t_list *attr, int size)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < ft_lstsize(attr))
			free(strdup_copy[i][j]);
		free(strdup_copy[i]);
	}
	free(strdup_copy);
}
