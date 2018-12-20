# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 18:31:25 by rkulahin          #+#    #+#              #
#    Updated: 2018/12/10 11:21:18 by rkulahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=*.c
OBJECTS=*.o

all: $(NAME)

$(NAME):
	@gcc -I . -c $(SRCS) -Wall -Wextra -Werror
	@ar -rcs $(NAME) $(OBJECTS)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all