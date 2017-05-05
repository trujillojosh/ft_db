/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:46:11 by jtrujill          #+#    #+#             */
/*   Updated: 2017/05/03 23:24:02 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>

t_list	*get_attr(void);
int		main(void);
int		ft_lstsize(t_list *lst);
char	***create_db(int size, t_list *attr);
char	*ft_itoa(int n);
int		ft_int_len(int nb);
char	***user_populate(int size, t_list *attr);
char	*fill_data(char *content);
int		another_entry(void);
int 	get_option(void);
char	*ft_strjoin(char const *s1, char const *s2);
char	*new_filename(char *str);
void	save_db(t_list *attr, char ***data);
t_list	*curr_saves(void);
char	*save_options(t_list *save);
char	***read_csv(char *save);
void	print_entry(int i, char ***data, t_list *attr);
char	*csv_std(char *str);
t_list	*split_csv(char *str);
t_list	*read_attr(FILE *fp, int mode);
t_list 	*new_entry_field(t_list *attr, int id);
char	***add_entry(t_list *attr, char ***data);

#endif
