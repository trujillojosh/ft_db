# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 17:31:50 by jtrujill          #+#    #+#              #
#    Updated: 2017/05/01 17:34:27 by jtrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_db
INC = -I ft_db.h
FLAGS = gcc
SRCS = main.c ft_print_list.c create_db.c user_new.c save_db.c load_db.c print_entry.c csv_format.c

all: $(NAME)

$(NAME):
	make -C libft
	$(FLAGS) $(INC) -o $(NAME) $(SRCS) -L libft/ -lft -g

clean:
	make clean -C libft
	rm -rf ft_db.dSYM

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
