/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:02 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:51:49 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	rrr(t_list **lsta, t_list **lstb)
{
	if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) > 1)
	{
		revers_rotate_list(lsta);
		revers_rotate_list(lstb);
		ft_putendl_fd("rrr", 1);
	}
	else if (ft_lstsize(*lsta) > 1 && ft_lstsize(*lstb) <= 1)
		rra(lsta);
	else if (ft_lstsize(*lstb) > 1 && ft_lstsize(*lsta) <= 1)
		rrb(lstb);
}
