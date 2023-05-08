/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_circular_list_desc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:00:06 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/08 17:08:42 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*sort in descending order a list that is already circular sorted in 
descending order */
void	sort_circular_list_desc(t_list	**lst)
{
	int	lstsize;

	lstsize = ft_lstsize(*lst);
	while (1)
	{
		if (is_sorted_list_desc(*lst))
			break ;
		if (index_of_list_max(*lst) >= (lstsize / 2))
			rrb(lst);
		else
			rb(lst);
	}
}
