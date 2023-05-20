/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:21 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 09:22:21 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	pa_bonus(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	if (ft_lstsize(*lstb) > 0)
	{
		tmp = *lstb;
		*lstb = (*lstb)->next;
		ft_lstadd_front(lsta, tmp);
	}
}
