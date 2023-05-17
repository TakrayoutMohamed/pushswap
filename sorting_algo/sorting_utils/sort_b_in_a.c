/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_in_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:54:30 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/17 03:52:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"


void	use_rb_rrb(t_list **b, int index)
{
	if (index + 1 - ft_lstsize(*b) % 2 <= ft_lstsize(*b) / 2)
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

	choose = 5;
		// printf("\nheeeeere1\n");
	// if (position + 1 <= (ft_lstsize(*a) / 2) && index + 1 <= (ft_lstsize(*b) / 2))
	// 	rr(a, b);
	// else if (position + 1 > (ft_lstsize(*a) / 2) && index + 1 > (ft_lstsize(*b) / 2))
	// 	rrr(a, b);
	// else
	{
		if (position < index)
			moves = position;
		else
			moves = index;
		choose = 0; //rr
		if ((ft_lstsize(*a) - position < ft_lstsize(*b) - index))
		{
			if (moves >= (ft_lstsize(*a) - position))
			{
				moves = ft_lstsize(*a) - position;
				choose = 1;//rrr
			}
		}
		else if (moves >= ft_lstsize(*b) - index)
		{
			moves = ft_lstsize(*b) - index;
			choose = 1;//rrr
		}
		if (index + ft_lstsize(*a) - position < position + ft_lstsize(*b) - index)
		{
			if (moves > index + ft_lstsize(*a) - position)
			{
				moves = index + ft_lstsize(*a) - position;
				choose = 2;// rb rra
			}
		}
		else if (moves > position + ft_lstsize(*b) - index)
		{
			moves = position + ft_lstsize(*b) - index;
			choose = 3;// rb rra
		}
		if (choose == 0)
		{
			rr(a, b);
		}
		else if (choose == 1)
		{
			rrr(a, b);
		}
		else if (choose == 2)
		{
			use_rb_rrb(b, index);
			use_ra_rra(a, position);
		}
		else if (choose == 3)
		{
			use_ra_rra(a, position);
			use_rb_rrb(b, index);
		}
	}
}


/*conditions of the needed move to use while adding b to a*/
void	sort_b_in_a(t_list **a, t_list **b, int index, int position)
{
	if (position > 0 && index > 0)
	{
		// printf("\nheeeeere0\n");
		use_rr_rrr(a, b, index, position);
	}
	else if (position == 0 && index != 0)
	{
		// printf("\nheeeeere2\n");
		use_rb_rrb(b, index);
	}
	else if (position != 0 && index == 0)
	{
		// printf("\nheeeeere3\n");
		use_ra_rra(a, position);
	}
}
