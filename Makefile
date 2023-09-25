# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:40:12 by alsaeed           #+#    #+#              #
#    Updated: 2023/09/15 17:19:48 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/push_swap.c
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ 

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(LIBFT_LIB): 
		@make -C $(LIBFT_DIR)

clean:
		@rm -f $(OBJS)
		@make clean -C libft

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re