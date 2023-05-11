/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:36 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 00:18:53 by takra            ###   ########.fr       */
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

static int	get_position_of_prior_node(t_list **lst)
{
	int		moves_to_position;
	int		position_of_prior;
	t_list	*tmp;

	tmp = *lst;
	moves_to_position = 2147483647;
	while (tmp != NULL)
	{
		if (tmp->position + tmp->index < moves_to_position)
		{
			moves_to_position = tmp->position + tmp->index;
			position_of_prior = tmp->position;
		}
		tmp = tmp->next;
	}
	tmp = NULL;
	return (position_of_prior);
}

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

/*add elements of b to a in a circular sort*/
void	circular_list(t_list **a, t_list **b)
{
	int	index_of_prior_node;
	int	position_of_prior_node;

	fill_position_of_b_in_a(a, b);
	fill_indexes_of_a_b(a, b);
	while (ft_lstsize(*b))
	{
		while (ft_lstsize(*b) > 0)
		{
			fill_position_of_b_in_a(a, b);
			fill_indexes_of_a_b(a, b);
			index_of_prior_node = get_index_of_prior_node(b);
			position_of_prior_node = get_position_of_prior_node(b);
			// printf("p index = %d\np position = %d",index_of_prior_node,position_of_prior_node);
			// exit(0);
			// ft_putstr_fd("\nnumber = ",1);
			// ft_putnbr_fd((*b)->content ,1);
			// ft_putstr_fd(" and index = ",1);
			// ft_putnbr_fd((*b)->index ,1);
			// ft_putstr_fd(" and position = ",1);
			// ft_putnbr_fd((*b)->position ,1);
			// ft_putstr_fd("\n",1);
			if ( ft_lstsize(*b) > 0 && (*b)->index == 0 && (*b)->position == 0)
			{
				pa(a, b);
				break ;
			}
			sort_b_in_a(a, b, index_of_prior_node, position_of_prior_node);
		}
	}
}
