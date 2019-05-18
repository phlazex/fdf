# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/23 17:18:06 by mfahey            #+#    #+#              #
#    Updated: 2019/04/29 21:25:18 by mfahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = $(wildcard srcs/*.c)
OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))
INCL = /usr/local/include/
INCF = includes/
INCLB = libft/includes/
FLAGS = -Wall -Wextra -Werror
LMLX = /usr/local/lib/
FRAM =  -framework OpenGL -framework AppKit


all: $(NAME)

objs/%.o: srcs/%.c
	gcc -c $< -o $@ -I $(INCF) -I $(INCLB)

$(NAME): $(OBJS)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(OBJS) -I$(INCL) -I $(INCF) -I $(INCLB) -L $(LMLX) -lmlx -L libft/ -lft $(FRAM) 

clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
