/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_circular_sorted_desc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:49:23 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/08 15:10:48 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return true if the given lst is circular in descending order*/
int	is_circular_sorted_desc(t_list *lst)
{
	t_list	*tmp;
	int		nbr_of_less_than;

	nbr_of_less_than = 0;
	tmp = lst;
	if (!is_sorted_list_desc(lst))
	{
		while (tmp->next != NULL)
		{
			if (tmp->content < tmp->next->content)
				nbr_of_less_than++;
			if (nbr_of_less_than > 1)
				return (0);
			tmp = tmp->next;
		}
		if (lst->content > tmp->content && nbr_of_less_than == 1)
			return (0);
	}
	return (1);
}
