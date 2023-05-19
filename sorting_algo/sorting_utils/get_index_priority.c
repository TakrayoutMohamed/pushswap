/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_priority.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:00:47 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/19 22:46:16 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

static void	top_b_a(t_list *tmp, int *moves, int *index, int *choose)
{
	if (tmp->position > tmp->index)
	{
		if (tmp->position < *moves)
		{
			*moves = tmp->position;
			*index = tmp->index;
			*choose = 0;
		}
	}
	else if (tmp->index < *moves)
	{
		*moves = tmp->index;
		*index = tmp->index;
		*choose = 0;
	}
}

static int	top_half_of_b(t_list **b, int *choose, int *moves, int *i)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp && tmp->index + 1 - tmp->lstsize_b % 2 <= tmp->lstsize_b / 2)
	{
		if (tmp->position + 1 - tmp->lstsize_a % 2 < tmp->lstsize_a / 2)
		{
			top_b_a(tmp, moves, i, choose);
		}
		else
		{
			if (tmp->lstsize_a - tmp->position + tmp->index < *moves)
			{
				*moves = tmp->lstsize_a - tmp->position + tmp->index;
				*i = tmp->index;
				*choose = 2;
			}
		}
		tmp = tmp->next;
	}
	return (*i);
}

static void	bottom_b_a(t_list *tmp, int *moves, int *index, int *choose)
{
	if (tmp->lstsize_a - tmp->position > tmp->lstsize_b - tmp->index)
	{
		if (tmp->lstsize_a - tmp->position < *moves)
		{
			*moves = tmp->lstsize_a - tmp->position;
			*index = tmp->index;
			*choose = 1;
		}
	}
	else if (tmp->lstsize_b - tmp->index < *moves)
	{
		*moves = tmp->lstsize_b - tmp->index;
		*index = tmp->index;
		*choose = 1;
	}
}

static int	bottom_half_of_b(t_list **b, int *choose, int *moves, int *i)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp && tmp->index + 1 - tmp->lstsize_b % 2 <= tmp->lstsize_b / 2)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->position + 1 - tmp->lstsize_a % 2 < tmp->lstsize_a / 2)
		{
			if (tmp->position + tmp->lstsize_b - tmp->index < *moves)
			{
				*moves = tmp->position + tmp->lstsize_b - tmp->index;
				*i = tmp->index;
				*choose = 2;
			}
		}
		else
			bottom_b_a(tmp, moves, i, choose);
		tmp = tmp->next;
	}
	return (*i);
}

/*return the index of the considered as prior number*/
int	get_index_priority(t_list **a, t_list **b)
{
	int		moves;
	int		index;
	int		choose;

	choose = 10;
	moves = 2147483647;
	top_half_of_b(b, &choose, &moves, &index);
	bottom_half_of_b(b, &choose, &moves, &index);
	sort_b_in_a(a, b, &index, choose);
	return (index);
}
