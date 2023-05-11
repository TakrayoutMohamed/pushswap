/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:21 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 00:23:38 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	pa(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	if (ft_lstsize(*lstb) > 0)
	{
		tmp = *lstb;
		*lstb = (*lstb)->next;
		ft_lstadd_front(lsta, tmp);
		ft_putendl_fd("pa", 1);
	}
}
