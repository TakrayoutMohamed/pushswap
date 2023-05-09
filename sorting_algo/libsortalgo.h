/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsortalgo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:35:07 by takra             #+#    #+#             */
/*   Updated: 2023/05/08 21:52:34 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSORTALGO_H
# define LIBSORTALGO_H
# include "./../libpushswap.h"

void	del(int content);
int		max_array(int array[], int arraylen);
int		index_of_list_max(t_list *lst);
int		get_right_position(t_list *lst, int value);
void	nbr_moves_to_position(t_list **a, t_list **b);
int		get_less_nbr_moves(t_list **lst);
int		is_circular_sorted(t_list *lst);
int		is_circular_sorted_desc(t_list *lst);
int		lis_len(int array[], int arraylen);
int		*lis(int array[], int arraylen);
int		max_array(int array[], int arraylen);
void	algo_sorting(t_list **a);
int		is_sorted_list(t_list *lst);
int		is_sorted_list_desc(t_list *lst);
int		is_list_max(t_list *lst, int value);
int		is_list_min(t_list *lst, int value);
void	sort_circular_list(t_list	**lst);
void	sort_circular_list_desc(t_list	**lst);
void	get_longest_increasement_lst(t_list **a, t_list **b);
void	circular_list(t_list **a, t_list **b);

#endif
