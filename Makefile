# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 10:17:24 by rkulahin          #+#    #+#              #
#    Updated: 2018/12/11 15:29:00 by rkulahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC	= src/count_func.c src/f_algoritm.c src/f_read.c src/main.c src/map_change.c src/tet_coord.c src/tet_map.c
OBJ = count_func.o f_algoritm.o f_read.o main.o map_change.o tet_coord.o tet_map.o
LIB = libft/libft.a
INCL = includes/
FLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(NAME) :
	@echo "\033[0;92mCompiling sources\033[0m"
	@echo "\033[42m  \033[0m\c"
	@echo "\033[42m  \033[0m\c"
	@$(MAKE) -C libft/
	@echo "\033[42m  \033[0m\c"
	@echo "\033[42m  \033[0m\c"
	@gcc -g -I $(INCL) -c $(SRC) $(FLAGS)
	@echo "\033[42m  \033[0m\c"
	@echo "\033[42m  \033[0m\c"
	@gcc -g -o $(NAME) $(OBJ) $(LIB) $(FLAGS)
	@echo "\033[42m  \033[0m\c"
	@echo "\033[42m  \033[0m\c"
	@echo "\033[42m  \033[0m\c"
	@echo " \033[1;92mDone!\033[0m"
clean :
	@rm -rf $(OBJ)
	@$(MAKE) clean -C libft/
fclean : clean
	@$(MAKE) fclean -C libft/
	@rm -f $(NAME)
re : fclean all