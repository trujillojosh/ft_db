/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:31:16 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/02 18:43:07 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = (char *)malloc(sizeof(char *) * size);
	if (new == 0)
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
