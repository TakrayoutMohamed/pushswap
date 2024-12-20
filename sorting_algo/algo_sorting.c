/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:36:19 by takra             #+#    #+#             */
/*   Updated: 2023/05/12 16:13:32 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libsortalgo.h"

/*sort the list (a) in ascending order*/
void	algo_sorting(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (*a != NULL && !is_sorted_list(*a))
	{
		if (ft_lstsize(*a) == 3 && !is_circular_sorted(*a))
			sa(a);
		if (!is_circular_sorted(*a))
		{
			fill_indexes_of_a(a);
			get_longest_increasement_lst(a, &b);
		}
		if (ft_lstsize(b))
			circular_list(a, &b);
		sort_circular_list(a);
	}
}
