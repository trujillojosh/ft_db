/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:54:04 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/11 22:32:18 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *lnxt;

	lnxt = *alst;
	while (lnxt)
	{
		curr = lnxt->next;
		del(lnxt, lnxt->content_size);
		lnxt = curr;
	}
	*alst = NULL;
}
