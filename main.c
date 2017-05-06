/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 22:24:41 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/05 23:10:49 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static int	get_option(void)
{
	char	*opt;
	int		i;

	i = 0;
	printf("\n%s", "Please choose one of the following options, then press enter.");
	printf("\n%s", "[1] Create a new database");
	printf("\n%s", "[2] Load an existing one\n");
	get_next_line(0, &opt);
	i = atoi(opt);
	free(opt);
	return (i);
}

static int	db_menu(void)
{
	char	*opt;
	int		i;

	i = 0;
	printf("\n%s", "Please choose one of the following options, then press enter.");
	printf("\n%s", "[1] New Entry\n[2] Search\n[3] Save\n[4] Quit\n");
	get_next_line(0, &opt);
	i = atoi(opt);
	free(opt);
	return (i);
}

static int	init_data(char ****data, t_list **attr)
{
	int		opt;

	opt = get_option();
	if (opt == 1)
	{
		*attr = get_attr();
		*data = user_populate(ft_lstsize(*attr), *attr);
	}
	else if (opt == 2)
	{
		*attr = curr_saves();
		*data = read_csv(save_options(*attr));
		if (*data == NULL)
		{
			printf("\n%s", "File is either corrupted or does not exist");
			return (-1);
		}
		*attr = read_attr(NULL, 1);
	}
	else
		return (-1);
	return (1);
}

int			main(void)
{
	static char	***data;
	t_list		*attr;
	int			opt;
	int			menu;

	menu = 0;
	if (init_data(&data, &attr) < 0)
		return (-1);
	while (menu != 4)
	{
		menu = db_menu();
		if (menu == 1)
			add_entry(attr, data);
		else if (menu == 2)
		{
			opt = search_db(attr, data);
			if (opt >= 0)
				manage_entry(attr, &data, opt);
		}
		else if (menu == 3)
			save_db(attr, data);
	}
	return (0);
}
