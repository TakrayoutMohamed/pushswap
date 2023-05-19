/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:36:19 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 00:25:22 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

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
	t_list	*tmp2;

	tmp2 = *lst;
	if (ft_lstsize(*lst) > 1)
	{
		tmp = ft_lstlast(*lst);
		while ((*lst))
		{
			if ((*lst)->next == ft_lstlast(*lst))
				break ;
			(*lst) = (*lst)->next;
		}
		(*lst)->next = NULL;
		*lst = tmp2;
		tmp->next = *lst;
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
		ft_lstlast(*lst)->next = tmp;
		tmp->next = NULL;
	}
}

void	swap_list(t_list	**lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = (*lst)->next;
		ft_swap(&tmp->content, &(*lst)->content);
		ft_swap(&tmp->index, &(*lst)->index);
		ft_swap(&tmp->position, &(*lst)->position);
	}
}
