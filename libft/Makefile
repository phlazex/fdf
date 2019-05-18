# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 12:37:56 by vferry            #+#    #+#              #
#    Updated: 2019/03/23 17:22:06 by mfahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= $(wildcard srcs/*.c)
OBJS	= $(patsubst srcs/%.c,objs/%.o,$(SRCS))
INC		= includes/



all: $(NAME)

objs/%.o: srcs/%.c
	gcc -c $< -o $@ -I $(INC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all