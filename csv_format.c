/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csv_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:25:58 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/03 15:50:14 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

// char    *create_csv(char *str)
// {
//     // size_t    i;
//     // size_t    len;

//     // if (!str)
//     //     return (NULL);
//     // i = 0;
//     // len = strlen(str);
//     // while (str[i] != '\0')
//     // {
//     //     if (str[i] == ',')
//     //     {
//     //         str[0] = '\"';
//     //         str[len - 1] = '\"'; //either len or len -1
//     //     }
//     //     if (str[i] == '\"')
//     //         str[i + 1] = '\"';
//     //     i++;
//     // }
//     // return (str);
//     size_t		j;
//     size_t		len;
//     char 		*res;

//     if (!str)
//     	return (NULL);
//     j = 0;
//     len = strlen(str) + (ft_char_count(str, '\"') * 2);
//     if (ft_char_count(str, ',') > 0)
//     	len += 2;
//     res = ft_strnew(len);
//     while (*str != '\0')
//     {
//     	if ((ft_char_count(str, ',') > 0) && (j == 0))
//     		res[j] = '\"';

//     }

// }

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
		res[j] = *str;
		j++;
		str++;
	}
	return (res);
}

// char    **split_csv(char *str)
// {
//     size_t    i;
//     size_t    j;
//     char    **temp;
//     int        flag;

//     i = 0;
//     if (!(temp = (char**)malloc(sizeof(char*) * (strlen(str) + 1))))
//         return (NULL);
//     flag = 0;
//     while (*str != '\0')
//     {
//         j = 0;
//         while (*str++ != ',' && temp[i][j] != '\0')
//         {
//             if (*str == '\"')
//                 str++;
//             while (*str++ != '\"')
//                 temp[i][j] = *str;
//             temp[i][j] = *str;
//         }
//         temp[i][j] = '\0';
//         i++;
//     }
//     return (temp);
// }

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
// int		main(void)
// {
// 	// printf("%s\n", create_csv("josh, trujillo"));
// 	// printf("%s\n", csv_std("\"\"\"Blue Dog\"\", \"\"The Magician\"\"\""));
//  //    printf("%s\n", csv_std("\"\"josh, trujillo\"\""));
//  //    printf("%s\n", csv_std("\"\"Words and internal comma, test\"\""));
//  //    printf("%s\n", csv_std("\"djfajsd;fnjasld;fnjalskdnfjsdf asdfs dfasd fasd f\""));
//  //    printf("%s\n", csv_std("\"josh, trujillo\""));
//  //    printf("%s\n", csv_std("\"\"josh, trujillo\"\""));
//  //    printf("%s\n", csv_std("\"josh, trujillo\""));
//  //    printf("%s\n", csv_std("Sally Whittaker,2018,McCarren House,312,3.75"));
//  //    printf("%s\n", csv_std("josh, trujillo"));
//  //    printf("%s\n", csv_std("\"josh, trujillo\""));
//  //    printf("%s\n", csv_std("\"josh, trujillo\""));
//  //    printf("%s\n", csv_std("\"josh, trujillo\""));
//  //    printf("%s\n", csv_std("\"josh, trujillo\""));
// 	ft_print_list(split_csv("17,Paloma,Convery,pconveryg@prnewswire.com,\"Fem,ale\",7.101.62.13\""));
// 	return (0);
// }
