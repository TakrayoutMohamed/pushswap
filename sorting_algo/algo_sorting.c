/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:36:19 by takra             #+#    #+#             */
/*   Updated: 2023/05/10 20:18:19 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libsortalgo.h"

static void	fill_indexes_of_a(t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	if (ft_lstsize(*a) > 0)
	{
		while (tmp != NULL)
		{
			tmp->index = i++;
			tmp = tmp->next;
		}
	}
}

// static void	fill_positions_of_a(t_list **a)
// {
// 	t_list	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = *a;
// 	if (ft_lstsize(*a) > 0)
// 	{
// 		while (tmp != NULL)
// 		{
// 			tmp->position = i++;
// 			tmp = tmp->next;
// 		}
// 	}
// }

/*sort the list a in ascending order*/
void	algo_sorting(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (*a != NULL && !is_sorted_list(*a))
	{
		if (!is_circular_sorted(*a))
		{
			if ((*a)->content > (*a)->next->content)
				sa(a);
			fill_indexes_of_a(a);
			get_longest_increasement_lst(a, &b);
		}
		if (ft_lstsize(b))
			circular_list(a, &b);
		sort_circular_list(a);
	}
}
