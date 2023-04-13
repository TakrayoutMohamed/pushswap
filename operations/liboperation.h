/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liboperation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:31:10 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 16:08:58 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBOPERATION_H
# define LIBOPERATION_H
# include "./../libpushswap.h"

void	revers_rotate_list(t_list	**lst);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lsta, t_list **lstb);
void	rotate_list(t_list	**lst);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lsta, t_list **lstb);
void	swap_list(t_list	**lst);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lsta, t_list **lstb);
void	pa(t_list **lsta, t_list **lstb);
void	pb(t_list **lstb, t_list **lsta);

#endif
