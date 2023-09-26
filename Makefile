# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:40:12 by alsaeed           #+#    #+#              #
#    Updated: 2023/09/26 15:24:52 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(NAME): all

all: 
	@make all -C srcs

clean:
	@make clean -C srcs

fclean: clean
	@make fclean -C srcs

re: fclean all