/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:19 by takra             #+#    #+#             */
/*   Updated: 2023/04/12 15:04:48 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libsorting.h"

static void	del(int content)
{
	content = 0;
	(void)content;
}

void	pb(t_list **lstb, t_list **lsta)
{
	t_list	*tmp;

	if (ft_lstsize(*lsta) > 0)
	{
		tmp = *lsta;
		ft_lstadd_front(lstb, ft_lstnew((*lsta)->content));
		tmp = tmp->next;
		ft_lstdelone(*lsta, del);
		(*lsta) = tmp;
		tmp = NULL;
		ft_putendl_fd("pb", 1);
	}
	else
		ft_putendl_fd("you tried to push from a to b but a is empty", 1);
}
