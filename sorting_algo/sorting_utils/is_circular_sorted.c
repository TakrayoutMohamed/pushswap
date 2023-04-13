/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_circular_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:06:54 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:08:56 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return true if the given lst is circular in ascending order*/
int	is_circular_sorted(t_list *lst)
{
	t_list	*tmp;
	int		nbr_of_grather_than;

	nbr_of_grather_than = 0;
	tmp = lst;
	if (!is_sorted_list(lst))
	{
		while (tmp->next != NULL)
		{
			if (tmp->content > tmp->next->content)
				nbr_of_grather_than++;
			if (nbr_of_grather_than > 1)
				return (0);
			tmp = tmp->next;
		}
	}
	if (lst->content < tmp->content)
		return (0);
	return (1);
}
