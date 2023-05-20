/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:51:31 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 08:01:36 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	rr_bonus(t_list **lsta, t_list **lstb)
{
	if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) > 1)
	{
		rotate_list(lsta);
		rotate_list(lstb);
	}
	else if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) <= 1)
		ra_bonus(lsta);
	else if (ft_lstsize(*lstb) > 1 && ft_lstsize(*lsta) <= 1)
		rb_bonus(lstb);
}
