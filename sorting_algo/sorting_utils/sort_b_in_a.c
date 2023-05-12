/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_in_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:54:30 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/12 00:55:20 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*conditions of the needed move to use while adding b to a*/
void	sort_b_in_a(t_list **a, t_list **b, int index, int position)
{
	if (position > 0 && index > 0)
	{
		if (position + index <= ft_lstsize(*a) / 2)
			rr(a, b);
		else
			rrr(a, b);
	}
	else if (position == 0 && index != 0)
	{
		if (index > ft_lstsize(*b) / 2)
			rrb(b);
		else
			rb(b);
	}
	else if (position != 0 && index == 0)
	{
		if (position > ft_lstsize(*a) / 2)
			rra(a);
		else
			ra(a);
	}
}
