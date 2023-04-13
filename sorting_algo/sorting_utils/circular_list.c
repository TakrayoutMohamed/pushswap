/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:36 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 14:56:32 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*add elements of b to a in a circular sort*/
void	circular_list(t_list **a, t_list **b)
{
	while (ft_lstsize(*b))
	{
		if (get_right_position(*a, (*b)->content) == 0)
			pa(a, b);
		else
		{
			if (get_right_position(*a, (*b)->content) > (ft_lstsize(*a) / 2))
				rra(a);
			else
				ra(a);
			if (get_right_position(*a, (*b)->content) == 0)
				pa(a, b);
		}
	}
}
