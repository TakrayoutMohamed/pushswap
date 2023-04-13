/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_increasement_lst.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:13 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 14:57:07 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*keep the langest increasment subsequence in the list a and push others to b*/
void	get_longest_increasement_lst(t_list **a, t_list **b)
{
	int		*lis_array;
	int		array_lis_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	array_lis_len = lis_len(lst_to_array(*a), ft_lstsize(*a));
	lis_array = lis(lst_to_array(*a), ft_lstsize(*a));
	if (ft_lstsize(*a) == 3)
		sa(a);
	while (1)
	{
		if (ft_lstsize(*a) == 3 && !is_circular_sorted(*a))
			sa(a);
		if (is_circular_sorted(*a))
			break ;
		if (j < array_lis_len && i == lis_array[j] && j++ > -1)
			ra(a);
		else
			pb(b, a);
		i++;
	}
	free(lis_array);
}
