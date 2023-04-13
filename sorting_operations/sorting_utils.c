/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:36:19 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 11:40:35 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libsorting.h"

static void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	revers_rotate_list(t_list	**lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = ft_lstnew(ft_lstlast(*lst)->content);
		ft_lstadd_front(lst, tmp);
		tmp = *lst;
		while ((*lst))
		{
			if ((*lst)->next == ft_lstlast(*lst))
				break ;
			(*lst) = (*lst)->next;
		}
		ft_lstdelone(ft_lstlast(*lst), del);
		(*lst)->next = NULL;
		*lst = tmp;
	}
}

void	rotate_list(t_list	**lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstadd_back(lst, ft_lstnew(tmp->content));
		ft_lstdelone(tmp, del);
		tmp = NULL;
	}
}

void	swap_list(t_list	**lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = (*lst)->next;
		ft_swap(&tmp->content, &(*lst)->content);
	}
}
