/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:36 by takra             #+#    #+#             */
/*   Updated: 2023/05/09 19:48:53 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

static int	get_index_of_prior_node(t_list **lst)
{
	int		moves_to_position;
	int		index_of_prior;
	t_list	*tmp;

	tmp = *lst;
	moves_to_position = 2147483647;
	while (tmp != NULL)
	{
		if (tmp->position + tmp->index < moves_to_position)
		{
			moves_to_position = tmp->position + tmp->index;
			index_of_prior = tmp->index;
		}
		tmp = tmp->next;
	}
	tmp = NULL;
	return (index_of_prior);
}

void	sort_b_in_a(t_list **a, t_list **b)
{

}

static void	fill_position_of_b_in_a(t_list **b, t_list **a)
{
	t_list	*tmp;
	int		i;
	int		right_position;

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
			tmp->position = i++;
			tmp = tmp->next;
		}
	}
	i = 0;
	tmp = *b;
	if (ft_lstsize(*b) > 0)
	{
		while (tmp != NULL)
		{
			tmp->position = i++;
			tmp = tmp->next;
		}
	}
}

/*add elements of b to a in a circular sort*/
void	circular_list(t_list **a, t_list **b)
{
	int	index_of_prior_node;

	while (ft_lstsize(*b))
	{
		fill_position_of_b_in_a(a, b);
		fill_indexes_of_a_b(a, b);
		index_of_prior_node = get_index_of_prior_node(b);
		while (index_of_prior_node > 0)
		{
			if ((*b)->index != 0 && (*b)->position != 0)
			{
				break ;
			}
			sort_b_in_a(a, b);
			index_of_prior_node--;
		}
	}
}
