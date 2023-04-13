/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:01:22 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 11:44:15 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpushswap.h"

/*does nothing ,its only here becouse of the prototype of lstclear(lst, del)*/
void	del(int content)
{
	content = 0;
	(void)content;
}

/*return true if the given value is greater than all elements of lst*/
int	is_list_max(t_list *lst, int value)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (value < tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*return true if the given value is smaller than all elements of lst*/
int	is_list_min(t_list *lst, int value)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (value > tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*return the index of the max element of the list lst*/
int	index_of_list_max(t_list *lst)
{
	int		indexmax;
	int		max;
	int		i;
	t_list	*tmp;

	indexmax = 0;
	i = 0;
	tmp = lst;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content >= max)
		{
			max = tmp->content;
			indexmax = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (indexmax);
}

/*return the index that the value should be in to still have lst circular*/
int	get_right_position(t_list *lst, int value)
{
	t_list	*tmp;
	int		position;

	tmp = lst;
	position = 0;
	if (ft_lstlast(lst)->content < value && lst->content > value)
		return (position);
	else if (is_list_max(lst, value) || is_list_min(lst, value))
		position = index_of_list_max(lst) + 1;
	else
	{
		while (tmp != NULL && tmp->next != NULL)
		{
			position++;
			if (tmp->content < value && tmp->next->content > value)
				return (position);
			tmp = tmp->next;
		}
	}
	if (position == ft_lstsize(lst))
		position = 0;
	return (position);
}

/*return true if the given lst is sorted in ascending order*/
int	is_sorted_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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

/*sort a list that is already circular sorted*/
void	sort_circular_list(t_list	**lst)
{
	int	lstsize;

	lstsize = ft_lstsize(*lst);
	while (1)
	{
		if (is_sorted_list(*lst))
			break ;
		if (index_of_list_max(*lst) >= (lstsize / 2))
			rra(lst);
		else
			ra(lst);
	}
}

/*return the number of langest increasement subsequence in a given array*/
int	lis_len(int array[], int arraylen)
{
	int	len;
	int	*lis;
	int	i;
	int	j;

	i = 0;
	len = 0;
	lis = (int *)malloc (sizeof(int) * arraylen);
	if (!lis)
		return (free(array), 0);
	while (i < arraylen)
		lis[i++] = 1;
	i = -1;
	while (++i < arraylen)
	{
		j = -1;
		while (++j < i)
			if (array[i] > array[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
	len = max_array(lis, arraylen);
	return (free(array), free(lis), len);
}

/*keep the langest increasment subsequence in the list a and push others to b*/
void	get_longest_increasement_lst(t_list **a, t_list **b)
{
	int		*lis_array;
	int		array_lis_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	array_lis_len = lis_len(lst_to_array(*a), ft_lstsize(*a));
	lis_array = lis(lst_to_array(*a), ft_lstsize(*a));
	if (ft_lstsize(*a) == 3)
		sa(a);
	while (1)
	{
		if (ft_lstsize(*a) == 3 && !is_circular_sorted(*a))
			sa(a);
		if (is_circular_sorted(*a))
			break ;
		if (j < array_lis_len && i == lis_array[j] && j++ > -1)
			ra(a);
		else
			pb(b, a);
		i++;
	}
	free(lis_array);
}

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

/*sort the list a in ascending order*/
void	algo_sorting(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (!is_sorted_list(*a))
	{
		if (!is_circular_sorted(*a))
		{
			get_longest_increasement_lst(a, &b);
		}
		if (ft_lstsize(b))
			circular_list(a, &b);
		sort_circular_list(a);
	}
}
