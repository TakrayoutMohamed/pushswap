/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_increasement_lst.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:13 by takra             #+#    #+#             */
/*   Updated: 2023/05/12 16:23:00 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return the position of the last node to be poped up from top*/
static int	nearest_index_from_top(int array[], int arraylen, t_list *tmp)
{
	int		position;
	int		i;

	i = 0;
	position = ft_lstsize(tmp) + 1;
	while (tmp != NULL && i < ft_lstsize(tmp) / 2)
	{
		if (is_in_array(array, arraylen, tmp->index))
		{
			position = tmp->position;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (position);
}

/*return the position of the first node to be poped from the bottom*/
static int	nearest_index_from_bottom(int array[], int arraylen, t_list *tmp)
{
	int		position;
	int		i;

	i = 0;
	position = ft_lstsize(tmp) + 1;
	while (tmp != NULL && i < ft_lstsize(tmp) / 2)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (is_in_array(array, arraylen, tmp->index))
		{
			position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (position);
}

/*used to push non lis nodes from stack a to b*/
static void	push_non_lis(int non_lis[], int arraylen, t_list **a, t_list **b)
{
	int	top_position;
	int	bottom_position;

	top_position = nearest_index_from_top(non_lis, arraylen, *a);
	bottom_position = nearest_index_from_bottom(non_lis, arraylen, *a);
	if (is_in_array(non_lis, arraylen, (*a)->index))
		pb(b, a);
	else
	{
		if (top_position < (ft_lstsize(*a) - bottom_position))
			ra(a);
		else
			rra(a);
		if (ft_lstsize(*a) == 3 && !is_circular_sorted(*a))
			sa(a);
	}
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
