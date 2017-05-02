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
SRCS = ft_lstnew.c ft_lstsize.c ft_main.c ft_print_list.c create_db.c ft_itoa.c ft_int_len.c

all: $(NAME)

$(NAME):
	$(FLAGS) $(INC) -o $(NAME) $(SRCS) -g

clean:
	rm -rf ft_db.dSYM

fclean: clean
	rm -rf $(NAME)

re: fclean all
