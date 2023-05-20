/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:46:47 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 08:03:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	ss_bonus(t_list **lsta, t_list **lstb)
{
	if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) > 1)
	{
		swap_list(lsta);
		swap_list(lstb);
	}
	else if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) <= 1)
		sa_bonus(lsta);
	else if (ft_lstsize(*lstb) > 1 && ft_lstsize(*lsta) <= 1)
		sb_bonus(lstb);
}
