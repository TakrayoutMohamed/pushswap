/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:36 by takra             #+#    #+#             */
/*   Updated: 2023/05/15 17:16:41 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return the index of the considered as prior number*/
static int	get_index_of_prior_node(t_list **lst, int lstsize_a)
{
	int		moves_to_position;
	int		index_of_prior;
	t_list	*tmp;

	tmp = *lst;
	moves_to_position = 2147483647;
	while (tmp != NULL && tmp->index + 1 - ft_lstsize(*lst) % 2 <= ft_lstsize(*lst) / 2)
	{
		if (tmp->position + 1 - lstsize_a % 2 <= (lstsize_a / 2))
		{
			if (tmp->position + tmp->index <= moves_to_position)
			{
				moves_to_position = tmp->position + tmp->index;
				index_of_prior = tmp->index;
			}
		}
		else
		{
			if (lstsize_a - tmp->position + tmp->index <= moves_to_position)
			{
				moves_to_position = lstsize_a - tmp->position + tmp->index;
				index_of_prior = tmp->index;
			}
		}
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		if (tmp->position + 1 - lstsize_a % 2 <= (lstsize_a / 2))
		{
			if (tmp->position + ft_lstsize(*lst) - tmp->index <= moves_to_position)
			{
				moves_to_position = tmp->position + ft_lstsize(*lst) - tmp->index;
				index_of_prior = tmp->index;
			}
		}
		else
		{
			if (lstsize_a - tmp->position + ft_lstsize(*lst) - tmp->index <= moves_to_position)
			{
				moves_to_position = lstsize_a - tmp->position + ft_lstsize(*lst) - tmp->index;
				index_of_prior = tmp->index;
			}
		}
		tmp = tmp->next;
	}
	tmp = NULL;
	return (index_of_prior);
}

/*return the position that the considered as prior number should be in at a*/
static int	get_position_of_prior_node(t_list **lst, int index)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (tmp->position);
		tmp = tmp->next;
	}
	tmp = NULL;
	return (0);
}

/*fill positions of list (b) with the index that it should be in list (a) 
to still have circular list*/
static void	fill_position_of_b_in_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	if (ft_lstsize(*b) > 0)
	{
		while (tmp != NULL)
		{
			tmp->position = get_right_position(*a, tmp->content);
			tmp = tmp->next;
		}
	}
}

/*fill the list's a , b indexes */
static void	fill_indexes_of_a_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	if (ft_lstsize(*a) > 0)
	{
		while (tmp != NULL)
		{
			tmp->index = i++;
			tmp = tmp->next;
		}
	}
	i = 0;
	tmp = *b;
	if (ft_lstsize(*b) > 0)
	{
		while (tmp != NULL)
		{
			tmp->index = i++;
			tmp = tmp->next;
		}
	}
}

/*add elements of b to a in a circular sort*/
void	circular_list(t_list **a, t_list **b)
{
	int	index_of_prior_node;
	int	position_of_prior_node;

	fill_position_of_b_in_a(a, b);
	fill_indexes_of_a_b(a, b);
	while (ft_lstsize(*b) > 0)
	{
		fill_position_of_b_in_a(a, b);
		fill_indexes_of_a_b(a, b);
		index_of_prior_node = get_index_of_prior_node(b, ft_lstsize(*a));
		position_of_prior_node = get_position_of_prior_node(b, index_of_prior_node);
		if ((*b)->index == 0 && (*b)->position == 0)
			pa(a, b);
		else
			sort_b_in_a(a, b, index_of_prior_node, position_of_prior_node);
	}
}
