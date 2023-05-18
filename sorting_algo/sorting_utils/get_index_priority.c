/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_priority.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:00:47 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/19 00:31:28 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

int	top_half_of_b(t_list **a, t_list **b, int *choose, int *moves, int *i)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp && tmp->index + 1 - ft_lstsize(*b) % 2 <= ft_lstsize(*b) / 2)
	{
		// top of a
		if (tmp->position + 1 - ft_lstsize(*a) % 2 < ft_lstsize(*a) / 2)
		{
			if (tmp->position > tmp->index)
			{
				if (tmp->position < *moves)
				{
					*moves = tmp->position;
					*i = tmp->index;
					*choose = 0;
				}
			}
			else if (tmp->index < *moves)
			{
				*moves = tmp->index;
				*i = tmp->index;
				*choose = 0;
			}
		}
		// bottom of a
		else
		{
			if (ft_lstsize(*a) - tmp->position + tmp->index < *moves)
			{
				*moves = ft_lstsize(*a) - tmp->position + tmp->index;
				*i = tmp->index;
				*choose = 2;
			}
		}
		tmp = tmp->next;
	}
	return (*i);
}

int	bottom_half_of_b(t_list **a, t_list **b, int *choose, int *moves, int *i)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp && tmp->index + 1 - ft_lstsize(*b) % 2 <= ft_lstsize(*b) / 2)
		tmp = tmp->next;
	// bottom of b
	while (tmp != NULL)
	{
		// top of a
		if (tmp->position + 1 - ft_lstsize(*a) % 2 < ft_lstsize(*a) / 2)
		{
			if (tmp->position + ft_lstsize(*b) - tmp->index < *moves)
			{
				*moves = tmp->position + ft_lstsize(*b) - tmp->index;
				*i = tmp->index;
				*choose = 2;
			}
		}
		// bottom of a
		else
		{
			if (ft_lstsize(*a) - tmp->position  > ft_lstsize(*b) - tmp->index)
			{
				if (ft_lstsize(*a) - tmp->position < *moves)
				{
					*moves = ft_lstsize(*a) - tmp->position;
					*i = tmp->index;
					*choose = 1;
				}
			}
			else if (ft_lstsize(*b) - tmp->index < *moves)
			{
				*moves = ft_lstsize(*b) - tmp->index;
				*i = tmp->index;
				*choose = 1;
			}
		}
		tmp = tmp->next;
	}
	return (*i);
}

/*return the index of the considered as prior number*/
int	get_index_priority(t_list **a, t_list **b)
{
	int		moves;
	int		index;
	int		position;
	int		choose;

	choose = 10;
	moves = 2147483647;
	index = top_half_of_b(a, b, &choose, &moves, &index);
	index = bottom_half_of_b(a, b, &choose, &moves, &index);
	position = get_position_of_index(b, index);
	sort_b_in_a(a, b, &index, &position, choose);
	return (index);
}
