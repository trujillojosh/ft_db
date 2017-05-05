/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 22:24:41 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/01 22:30:04 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		get_option(void)
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

int		db_menu(void)
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

int		main(void)
{
	static char	***data;
	t_list		*attr;
	t_list		*help;
	int			opt;
	int			menu;

	opt = get_option();
	help = NULL;
	if (opt == 1) //create new db
	{
		attr = get_attr();
		data = user_populate(ft_lstsize(attr), attr);
		// print_entry(1, data, attr);
	}
	else if (opt == 2)//access an existing one
	{
		attr = curr_saves();
		data = read_csv(save_options(attr));
		if (data == NULL)
		{
			printf("\n%s", "File is either corrupted or does not exist");
			return (-1);
		}
		attr = read_attr(NULL, 1);
		// printf("\n%s", save_options(attr));
		// data = read_csv(save_options(attr));
		// printf("\noption is --> %s", save_options(attr));
		// return (0);
	}
	else
		return (-1);
	while (menu != 4)
	{
		menu = db_menu();
		if (menu == 1)
			add_entry(attr, data);
		else if (menu == 3)
			save_db(attr, data);
	}
	// printf("\n%s\n%s\n%s", data[0][1], data[1][1], data[2][1]);
	return (0);
}
