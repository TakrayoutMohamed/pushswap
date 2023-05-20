/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liboperation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:31:10 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 08:05:47 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBOPERATION_H
# define LIBOPERATION_H
# include "./../../libpushswap.h"

void	revers_rotate_list(t_list	**lst);
void	rra_bonus(t_list **lst);
void	rrb_bonus(t_list **lst);
void	rrr_bonus(t_list **lsta, t_list **lstb);
void	rotate_list(t_list	**lst);
void	ra_bonus(t_list **lst);
void	rb_bonus(t_list **lst);
void	rr_bonus(t_list **lsta, t_list **lstb);
void	swap_list(t_list	**lst);
void	sa_bonus(t_list **lst);
void	sb_bonus(t_list **lst);
void	ss_bonus(t_list **lsta, t_list **lstb);
void	pa_bonus(t_list **lsta, t_list **lstb);
void	pb_bonus(t_list **lstb, t_list **lsta);

#endif
