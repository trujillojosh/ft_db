/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:52:45 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/01 10:22:29 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *s)
{
	int				nb;
	int				sign;
	unsigned char	*str;

	nb = 0;
	sign = 1;
	str = (unsigned char *)s;
	if (*str == '\0')
		return (0);
	while (*str < 33)
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nb = (nb * 10) + (*str - '0') * sign;
		str++;
	}
	return (nb);
}
