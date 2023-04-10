# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takra <takra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 18:37:53 by mohtakra          #+#    #+#              #
#    Updated: 2023/04/09 17:53:14 by takra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
LIBFT= ./Libft-42/libft.a
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SORTINGPATH=./sorting_operations/

SRC =  ft_utils.c push_swap.c algo_lis.c\
		$(SORTINGPATH)pa.c $(SORTINGPATH)pb.c $(SORTINGPATH)ra.c \
		$(SORTINGPATH)rb.c $(SORTINGPATH)rr.c $(SORTINGPATH)rra.c \
		$(SORTINGPATH)rrb.c $(SORTINGPATH)rrr.c $(SORTINGPATH)sa.c \
		$(SORTINGPATH)sb.c $(SORTINGPATH)ss.c \
		$(SORTINGPATH)sorting_utils.c

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