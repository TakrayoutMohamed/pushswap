/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:11:53 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/12 16:02:14 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "./Libft-42/libft.h"
# include "./sorting_operations/libsorting.h"

int		check_args(char **str);
char	*ft_joinargvs(int argc, char **argv);
char	*ft_strtrim_free(char *str, char *set);
t_list	*matrix_to_lst(char **matrix);
int		*lst_to_array(t_list *lst);
int		lst_duplcate_node(t_list *lst);
int		is_int(char **matrix, t_list *lst);
void	free_matrix(char **matrix);
int		*lis(int array[], int arraylen);
int		min_value_lis_index(int array[], int lis[], int lis_value, int arrayl);
void	algo_sorting(t_list **a);
int		is_sorted_list(t_list *lst);
int		is_list_max(t_list *lst, int value);
int		is_list_min(t_list *lst, int value);
void	sort_circular_list(t_list	**lst);
void	get_longest_increasement_lst(t_list **a, t_list **b);
void	circular_list(t_list **a, t_list **b);

#endif