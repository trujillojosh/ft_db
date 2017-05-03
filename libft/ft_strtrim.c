/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:13:05 by jtrujill          #+#    #+#             */
/*   Updated: 2016/12/03 16:50:00 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned char	*str;
	char			*new;
	int				len;
	int				i;
	int				j;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	len = ft_strlen((const char *)str) - 1;
	j = 0;
	i = 0;
	while (ft_wspace_check(str[i]) == 1)
		i++;
	if ((ft_strlen((const char *)&str[i])) < 1)
		return (ft_strdup(""));
	while (ft_wspace_check(str[len]) == 1)
		len--;
	len = (len - i) + 1;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0)
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}
