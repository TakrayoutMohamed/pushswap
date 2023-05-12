/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_increasement_lst.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:13 by takra             #+#    #+#             */
/*   Updated: 2023/05/12 01:54:13 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*fill the position filled in list (a)*/
void	fill_positions_of_a(t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	if (ft_lstsize(*a) > 0)
	{
		while ((*a) != NULL)
		{
			(*a)->position = i++;
			(*a) = (*a)->next;
		}
	}
	*a = tmp;
}

/*return the position of the nearest node to be poped up from top*/
static int	nearest_index_from_top(int array[], int arraylen, t_list *tmp)
{
	int		position;
	int		nbr_moves;
	int		i;

	i = -1;
	position = 0;
	nbr_moves = 20000000;
	while (tmp != NULL && ++i > -3)
	{
		if (is_in_array(array, arraylen, tmp->index))
		{
			if (i + 1 < ft_lstsize(tmp) / 2 && nbr_moves > tmp->position)
			{
				position = tmp->position;
				nbr_moves = tmp->position;
			}
		}
		tmp = tmp->next;
	}
	return (position);
}

/*return the position of the nearest node to be poped from the bottom*/
static int	nearest_index_from_bottom(int array[], int arraylen, t_list *tmp)
{
	int		position;
	int		nbr_moves;
	int		i;

	i = -1;
	position = 0;
	nbr_moves = 20000000;
	while (tmp != NULL && ++i + 1 >= ft_lstsize(tmp) / 2)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (is_in_array(array, arraylen, tmp->index))
		{
			if (nbr_moves > ft_lstsize(tmp) - tmp->position + 1)
			{
				position = tmp->position;
				nbr_moves = ft_lstsize(tmp) - tmp->position;
			}
		}
		tmp = tmp->next;
	}
	return (position);
}

void	push_non_lis(int non_lis_array[], int arraylen, t_list **a, t_list **b)
{
	int	top_position;
	int	bottom_position;

	top_position = nearest_index_from_top(non_lis_array, arraylen, *a);
	bottom_position = nearest_index_from_bottom(non_lis_array, arraylen, *a);
	if (is_in_array(non_lis_array, arraylen, (*a)->index))
		pb(b, a);
	if (top_position <= (ft_lstsize(*a) - bottom_position + 1))
		ra(a);
	else
		rra(a);
	if (ft_lstsize(*a) == 3 && !is_circular_sorted(*a))
		sa(a);
}

/*keep the langest increasment subsequence in the list a and push others to b*/
void	get_longest_increasement_lst(t_list **a, t_list **b)
{
	int		*lis_array;
	int		*non_lis_array;
	int		lis_array_len;
	int		non_lis_array_len;

	lis_array_len = lis_len(lst_to_array(*a), ft_lstsize(*a));
	lis_array = lis(lst_to_array(*a), ft_lstsize(*a));
	non_lis_array = non_lis(lis_array, lis_array_len, ft_lstsize(*a));
	non_lis_array_len = ft_lstsize(*a) - lis_array_len;
	while (!is_circular_sorted(*a))
	{
		fill_positions_of_a(a);
		push_non_lis(non_lis_array, non_lis_array_len, a, b);
	}
	free(lis_array);
	free(non_lis_array);
}
