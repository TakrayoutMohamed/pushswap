/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:02 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 08:02:40 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	rrr_bonus(t_list **lsta, t_list **lstb)
{
	if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) > 1)
	{
		revers_rotate_list(lsta);
		revers_rotate_list(lstb);
	}
	else if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) <= 1)
		rra_bonus(lsta);
	else if (ft_lstsize(*lstb) > 1 && ft_lstsize(*lsta) <= 1)
		rrb_bonus(lstb);
}
