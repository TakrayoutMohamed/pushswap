/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:21 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:52:21 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	pa(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	if (ft_lstsize(*lstb) > 0)
	{
		tmp = *lstb;
		ft_lstadd_front(lsta, ft_lstnew((*lstb)->content));
		tmp = tmp->next;
		ft_lstdelone(*lstb, del);
		(*lstb) = tmp;
		tmp = NULL;
		ft_putendl_fd("pa", 1);
	}
}
