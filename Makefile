# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 18:37:53 by mohtakra          #+#    #+#              #
#    Updated: 2022/12/26 18:49:06 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC =  ft_isdigit.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_utils.c push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) -o $@ $(OBJ)
		@echo "the files has ben archived successfully"
		@chmod 777 push_swap

%.o: %.c libpushswap.h
		@$(CC) -I. $(CFLAGS) -o $@ -c $< 
		@echo "the file $@ has been created from $<"


clean:
		@$(RM) $(OBJ)
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the libft.a has been deleted"
	
re: fclean all

.PHONE : clean $(NAME) all fclean bonus re