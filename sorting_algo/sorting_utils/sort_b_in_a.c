/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_in_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:54:30 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/18 23:01:16 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"


void	use_rb_rrb(t_list **b, int *index)
{
	if (*index == 0)
		return ;
	if (*index + 1 - ft_lstsize(*b) % 2 <= ft_lstsize(*b) / 2)
	{
		while (*index > 0)
		{
			rb(b);
			(*index)--;
		}
	}
	else
	{
		while (*index < ft_lstsize(*b))
		{
			rrb(b);
			(*index)++;
		}
		if (*index == ft_lstsize(*b))
			*index = 0;
	}
		
}

void	use_ra_rra(t_list **a, int *position)
{
	if (*position == 0)
		return ;
	if (*position + 1 - ft_lstsize(*a) % 2 <= ft_lstsize(*a) / 2)
	{
		while (*position > 0)
		{
			ra(a);
			(*position)--;
		}
	}
	else
	{
		while (*position < ft_lstsize(*a))
		{
			rra(a);
			(*position)++;
		}
		if (*position == ft_lstsize(*a))
			*position = 0;
	}
}

void	use_rr(t_list **a, t_list **b, int *index, int *position)
{

	while (*index > 0 && *position > 0)
	{
		rr(a, b);
		(*index)--;
		(*position)--;
	}
}

void	use_rrr(t_list **a, t_list **b, int *index, int *position)
{

	while (*index < ft_lstsize(*b) && *position < ft_lstsize(*a))
	{
		rrr(a, b);
		(*index)++;
		(*position)++;
	}
	if (*position == ft_lstsize(*a))
		*position = 0;
	if (*index == ft_lstsize(*b))
		*index = 0;
}

/*conditions of the needed move to use while adding b to a*/
void	sort_b_in_a(t_list **a, t_list **b, int *index, int *position, int choose)
{
	if (choose == 0)
	{
		use_rr(a, b, index, position);
	}
	else if (choose == 1)
	{
		use_rrr(a, b, index, position);
	}
	use_rb_rrb(b, index);
	use_ra_rra(a, position);
}
