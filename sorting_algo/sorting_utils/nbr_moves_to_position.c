/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_moves_to_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:57:17 by takra             #+#    #+#             */
/*   Updated: 2023/05/09 19:20:54 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*fill the list b with the needed moves to be at its position index*/
static void	fill_nbr_moves_for_b(t_list **b, t_list **a)
{
	t_list	*tmp;
	int		i;
	int		right_position;

	i = 0;
	if (ft_lstsize(*b) > 0)
	{
		while (tmp != NULL)
		{
			right_position = get_right_position(*a, tmp->content);
			if (right_position > ft_lstsize(*a) / 2)
			{
				right_position = ft_lstsize(*a) - right_position;
			}
			tmp->position = i + right_position + 1;
			i++;
			tmp = tmp->next;
		}
	}
}

static void	fill_indexes_for_a(t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	if (ft_lstsize(*a) > 0)
	{
		while (tmp != NULL)
		{
			tmp->position = i++;
			tmp = tmp->next;
		}
	}
}

void	nbr_moves_to_position(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		i;

	i = 0;
	fill_indexes_for_a(a);
	fill_nbr_moves_for_b(b, a);
}
