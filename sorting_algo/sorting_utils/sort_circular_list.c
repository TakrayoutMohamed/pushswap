/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_circular_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:53:03 by takra             #+#    #+#             */
/*   Updated: 2023/05/15 18:48:02 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*sort a list that is already circular sorted*/
void	sort_circular_list(t_list	**lst)
{
	int	lstsize;

	lstsize = ft_lstsize(*lst);
	while (!is_sorted_list(*lst))
	{
		if (index_of_list_max(*lst) + 1 <= (lstsize / 2))
			ra(lst);
		else
			rra(lst);
	}
}
