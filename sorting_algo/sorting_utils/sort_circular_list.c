/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_circular_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:53:03 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 18:10:56 by takra            ###   ########.fr       */
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
		if (index_of_list_max(*lst) >= (lstsize / 2))
			rra(lst);
		else
			ra(lst);
	}
}
