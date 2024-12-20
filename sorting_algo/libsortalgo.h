/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsortalgo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:35:07 by takra             #+#    #+#             */
/*   Updated: 2023/05/19 20:48:29 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSORTALGO_H
# define LIBSORTALGO_H
# include "./../libpushswap.h"

void	del(int content);
int		max_array(int array[], int arraylen);
int		index_of_list_max(t_list *lst);
int		get_right_position(t_list *lst, int value);
void	fill_positions_of_a(t_list **a);
void	fill_indexes_of_a(t_list **a);
int		is_circular_sorted(t_list *lst);
int		lis_len(int array[], int arraylen);
int		*lis(int array[], int arraylen);
int		*non_lis(int lis_array[], int array_lis_len, int lstsize);
int		max_array(int array[], int arraylen);
void	algo_sorting(t_list **a);
int		is_sorted_list(t_list *lst);
int		is_list_max(t_list *lst, int value);
int		is_list_min(t_list *lst, int value);
void	sort_circular_list(t_list	**lst);
void	get_longest_increasement_lst(t_list **a, t_list **b);
void	circular_list(t_list **a, t_list **b);
int		get_index_priority(t_list **a, t_list **b);
int		get_position_of_index(t_list **lst, int index);
void	sort_b_in_a(t_list **a, t_list **b, int *index, int choose);
int		is_in_array(int array[], int array_len, int value);

#endif
