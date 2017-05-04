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

//char	*std_csv(char *str)
//{
//
//}

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

char    **split_csv(char *str)
{
    size_t    i;
    size_t    j;
    char    **temp;
    int        flag;

    i = 0;
    if (!(temp = (char**)malloc(sizeof(char*) * (strlen(str) + 1))))
        return (NULL);
    flag = 0;
    while (*str != '\0')
    {
        j = 0;
        while (*str++ != ',' && temp[i][j] != '\0')
        {
            if (*str == '\"')
                str++;
            while (*str++ != '\"')
                temp[i][j] = *str;
            temp[i][j] = *str;
        }
        temp[i][j] = '\0';
        i++;
    }
    return (temp);
}

int		main(void)
{
	printf("%s\n", csv_std("\"\"\"Blue Dog\"\", \"\"The Magician\"\"\""));
    printf("%s\n", csv_std("\"\"josh, trujillo\"\""));
    printf("%s\n", csv_std("\"\"Words and internal comma, test\"\""));
    printf("%s\n", csv_std("\"djfajsd;fnjasld;fnjalskdnfjsdf asdfs dfasd fasd f\""));
    printf("%s\n", csv_std("\"josh, trujillo\""));
    printf("%s\n", csv_std("\"\"josh, trujillo\"\""));
    printf("%s\n", csv_std("\"josh, trujillo\""));
    printf("%s\n", csv_std("Sally Whittaker,2018,McCarren House,312,3.75"));
    printf("%s\n", csv_std("josh, trujillo"));
    printf("%s\n", csv_std("\"josh, trujillo\""));
    printf("%s\n", csv_std("\"josh, trujillo\""));
    printf("%s\n", csv_std("\"josh, trujillo\""));
    printf("%s\n", csv_std("\"josh, trujillo\""));
	// char **test = split_csv("MPN,ITEM,Price,Description");
	// int		i = 0;
	// while (test[i] != NULL)
	// {
	// 	printf("\n%s", test[i]);
	// 	i++;
	// }
	// return (0);
}
