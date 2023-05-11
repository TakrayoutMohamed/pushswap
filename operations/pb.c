/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:19 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 00:23:45 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	pb(t_list **lstb, t_list **lsta)
{
	t_list	*tmp;

	if (ft_lstsize(*lsta) > 0)
	{
		tmp = *lsta;
		*lsta = (*lsta)->next;
		ft_lstadd_front(lstb, tmp);
		ft_putendl_fd("pb", 1);
	}
}
