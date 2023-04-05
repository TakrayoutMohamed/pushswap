# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takra <takra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 18:37:53 by mohtakra          #+#    #+#              #
#    Updated: 2023/04/04 11:18:50 by takra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
LIBFT= ./Libft-42/libft.a
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC =  ft_utils.c push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
		$(CC) -o $@ $(OBJ) $(LIBFT)
		@echo "the files has ben archived successfully"

%.o: %.c libpushswap.h
		$(CC) $(CFLAGS) -o $@ -c $<
		@echo "the file $@ has been created from $<"

$(LIBFT): 
	make -C ./Libft-42 

clean:
		@$(RM) $(OBJ)
		make -C ./Libft-42 clean
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		make -C ./Libft-42 fclean
		@echo "the libft.a has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) all fclean bonus re