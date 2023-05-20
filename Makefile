# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 18:37:53 by mohtakra          #+#    #+#              #
#    Updated: 2023/05/20 10:58:03 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
B_NAME=checker
CC=cc
LIBFT= ./Libft-42/libft.a
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
OPERATIONPATH=./operations/
B_OPERATIONPATH=./bonus/operations/
PARSINGPATH=./parsing/parsing_utils/
SORTINGPATH=./sorting_algo/sorting_utils/

SRCSORTING= $(SORTINGPATH)../algo_sorting.c $(SORTINGPATH)circular_list.c $(SORTINGPATH)del.c \
			$(SORTINGPATH)get_longest_increasement_lst.c $(SORTINGPATH)get_right_position.c \
			$(SORTINGPATH)index_of_list_max.c $(SORTINGPATH)max_array.c  $(SORTINGPATH)is_in_array.c\
			$(SORTINGPATH)is_list_max.c $(SORTINGPATH)is_list_min.c \
			$(SORTINGPATH)is_sorted_list.c\
			$(SORTINGPATH)lis_len.c $(SORTINGPATH)lis.c $(SORTINGPATH)non_lis.c\
			$(SORTINGPATH)sort_circular_list.c \
			$(SORTINGPATH)is_circular_sorted.c\
			$(SORTINGPATH)sort_b_in_a.c \
			$(SORTINGPATH)get_position_of_index.c $(SORTINGPATH)get_index_priority.c\
			$(SORTINGPATH)fill_indexes_of_a.c $(SORTINGPATH)fill_positions_of_a.c

SRCPARSING= $(PARSINGPATH)../is_valid_list.c $(PARSINGPATH)is_int.c \
			$(PARSINGPATH)lst_duplicate_node.c $(PARSINGPATH)is_only_nbrs.c

MAIN_PUSHSWAP= push_swap.c
MAIN_CHECKER= ./bonus/checker_bonus.c
SRC 	=  pushswap_utils.c \
			$(OPERATIONPATH)pa.c $(OPERATIONPATH)pb.c $(OPERATIONPATH)ra.c \
			$(OPERATIONPATH)rb.c $(OPERATIONPATH)rr.c $(OPERATIONPATH)rra.c \
			$(OPERATIONPATH)rrb.c $(OPERATIONPATH)rrr.c $(OPERATIONPATH)sa.c \
			$(OPERATIONPATH)sb.c $(OPERATIONPATH)ss.c \
			$(OPERATIONPATH)operation_utils.c

B_SRC 	=  ./bonus/apply_opperation.c \
			$(B_OPERATIONPATH)pa_bonus.c $(B_OPERATIONPATH)pb_bonus.c $(B_OPERATIONPATH)ra_bonus.c \
			$(B_OPERATIONPATH)rb_bonus.c $(B_OPERATIONPATH)rr_bonus.c $(B_OPERATIONPATH)rra_bonus.c \
			$(B_OPERATIONPATH)rrb_bonus.c $(B_OPERATIONPATH)rrr_bonus.c $(B_OPERATIONPATH)sa_bonus.c \
			$(B_OPERATIONPATH)sb_bonus.c $(B_OPERATIONPATH)ss_bonus.c 

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
OBJPARSING = $(SRCPARSING:.c=.o)
OBJSORTING = $(SRCSORTING:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MAIN_PUSHSWAP:.c=.o) $(OBJ) $(OBJPARSING) $(OBJSORTING)
		@$(CC) -o $@ $(MAIN_PUSHSWAP:.c=.o) $(OBJ) $(OBJPARSING) $(OBJSORTING) $(LIBFT)
		@echo "the files has ben archived successfully"

%.o: %.c ./libpushswap.h $(PARSINGPATH)../libparsing.h $(SORTINGPATH)../libsortalgo.h $(OPERATIONPATH)/liboperation.h $(B_OPERATIONPATH)/liboperation.h ./bonus/libchecker_bonus.h
		@$(CC) $(CFLAGS) -o $@ -c $<
		@echo "the file $@ has been created from $<"

$(LIBFT): 
	make -C ./Libft-42
bonus : $(B_OBJ) $(OBJ) $(MAIN_CHECKER:.c=.o) $(OBJPARSING) $(OBJSORTING) $(LIBFT)
		@$(CC) -o $(B_NAME) $(MAIN_CHECKER:.c=.o) $(OBJ) $(B_OBJ) $(OBJPARSING) $(OBJSORTING) $(LIBFT)

clean:
		@$(RM) $(OBJ) $(B_OBJ) $(OBJPARSING) $(OBJSORTING) $(MAIN_CHECKER:.c=.o) $(MAIN_PUSHSWAP:.c=.o)
		make -C ./Libft-42 clean
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME) $(B_NAME)
		make -C ./Libft-42 fclean
		@echo "the libft.a has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) all fclean bonus re