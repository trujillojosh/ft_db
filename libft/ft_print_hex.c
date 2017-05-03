/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:09:27 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/12 18:13:58 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_hex(int nb)
{
	if (nb < 16 && nb > 9)
		ft_putchar(nb + 87);
	else if ((nb / 16) >= 1)
	{
		ft_print_hex(nb / 16);
		ft_print_hex(nb % 16);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}
