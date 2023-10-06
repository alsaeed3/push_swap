# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:40:12 by alsaeed           #+#    #+#              #
#    Updated: 2023/10/06 19:02:11 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	../push_swap

SRCS =	pars_utils1.c push_swap.c push.c reverse_rotate.c rotate.c sorting2.c \
		swap.c
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = ../libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@cc $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "push_swap Compiled : \033[1;32mOK\n\033[0m"

$(LIBFT_LIB): 
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@if [ -e $(OBJS_DIR) ]; then \
		rm -rf $(OBJS_DIR); \
		echo "push_swap Clean : \033[32mOK\n\033[0m"; \
	fi

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		echo "push_swap Full-Clean : \033[32mOK\n\033[0m"; \
	fi

re: fclean all

.PHONY: all clean fclean re