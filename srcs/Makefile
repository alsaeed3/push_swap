# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:40:12 by alsaeed           #+#    #+#              #
#    Updated: 2023/09/28 15:22:28 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	../push_swap

SRCS =	moves_utils1.c moves_utils2.c pars_utils1.c push_swap.c dllst_utils.c \
		sorting2.c
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT_DIR = ../libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@cc $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "\033[1;32mpush_swap is Compiled Successfully\n\033[0m"

$(LIBFT_LIB): 
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@if [ -e $(OBJS_DIR) ]; then \
		rm -rf $(OBJS_DIR); \
		echo "\033[1;38;5;208mpush_swap Clean is Successful\n\033[0m"; \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		make fclean -C $(LIBFT_DIR); \
		echo "\033[1;31mpush_swap Full-Clean is Successful\n\033[0m"; \
	fi

re: fclean all

.PHONY: all clean fclean re