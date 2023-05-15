/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_in_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:54:30 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/15 19:27:12 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"


void	use_rb_rrb(t_list **b, int index)
{
	if (index + 1 - ft_lstsize(*b) % 2 < ft_lstsize(*b) / 2)
		rb(b);
	else
		rrb(b);
}

void	use_ra_rra(t_list **a, int position)
{
	if (position + 1 - ft_lstsize(*a) % 2 <= ft_lstsize(*a) / 2)
		ra(a);
	else
		rra(a);
}


void	use_rr_rrr(t_list **a, t_list **b, int index, int position)
{
	int	moves;
	int	choose;

	if (position + 1 <= (ft_lstsize(*a) / 2) && index + 1 <= (ft_lstsize(*b) / 2))
		rr(a, b);
	else if (position + 1 > (ft_lstsize(*a) / 2) && index + 1 > (ft_lstsize(*b) / 2))
		rrr(a, b);
	else
	{
		moves = position + index;
		choose = 0; //rr
		if (moves >= ft_lstsize(*a) - position + ft_lstsize(*b) - index)
		{
			moves = ft_lstsize(*a) - position + ft_lstsize(*b) - index;
			choose = 1;//rrr
		}
		if (moves > position + ft_lstsize(*b) - index)
		{
			moves = position + ft_lstsize(*b) - index;
			choose = 2;//rrb ra
		}
		if (moves > ft_lstsize(*a) - position + index)
			// moves = position + ft_lstsize(*b) - index;
			choose = 3;//rra rb
		if (choose == 0)
			rr(a, b);
		else if (choose == 1)
			rrr(a, b);
		else if (choose == 2 || choose == 3)
		{
			// if (ft_lstsize(*b) - index > position)
				use_ra_rra(a, position);
			// else
				// use_rb_rrb(b, index);
		}
		// else if (choose == 3)
		// {
		// 	if (ft_lstsize(*a) - position > index)
		// 		use_rb_rrb(b, index);
		// 	else
		// 		use_ra_rra(a, position);
		// }
	}
}


/*conditions of the needed move to use while adding b to a*/
void	sort_b_in_a(t_list **a, t_list **b, int index, int position)
{
	if (position > 0 && index > 0)
	{
		use_rr_rrr(a, b, index, position);
	}
	else if (position == 0 && index != 0)
	{
		use_rb_rrb(b, index);
	}
	else if (position != 0 && index == 0)
	{
		use_ra_rra(a, position);
	}
}
