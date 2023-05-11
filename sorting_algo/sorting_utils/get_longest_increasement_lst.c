/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_increasement_lst.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:13 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 20:18:21 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return true if the value exist in given array 
that have a lenght of array_len*/
int	is_in_array(int array[], int array_len, int value)
{
	int	i;

	i = 0;
	while (i < array_len)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

/*returns a pointer to an array filled with indexes of nodes that not a part
of longest increasement subsequence array (lis) */
int	*non_lis(int lis_array[], int array_lis_len, int lstsize)
{
	int	*no_lis;
	int	i;
	int	j;

	i = 0;
	j = 0;
	no_lis = (int *)malloc(sizeof(int) * (lstsize - array_lis_len));
	while (i < lstsize && j < lstsize - array_lis_len)
	{
		if (!is_in_array(lis_array, array_lis_len, i))
		{
			no_lis[j] = i;
			j++;
		}
		i++;
	}
	return (no_lis);
}


void	fill_positions_of_a(t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	if (ft_lstsize(*a) > 0)
	{
		while ((*a) != NULL)
		{
			(*a)->position = i++;
			(*a) = (*a)->next;
		}
	}
	*a = tmp;
}

static int	nearest_index(int array[], int arraylen, t_list *tmp)
{
	int		position;
	int		nbr_moves;
	int		i;

	i = -1;
	position = 0;
	nbr_moves = 20000000;
	while (tmp != NULL && ++i > -3)
	{
		if (is_in_array(array, arraylen, tmp->index))
		{
			if (++i + 1 < ft_lstsize(tmp) / 2 && nbr_moves > tmp->position)
			{
				position = tmp->position;
				nbr_moves = tmp->position;
			}
			if (i + 1 >= ft_lstsize(tmp) / 2 && nbr_moves > ft_lstsize(tmp) - tmp->position + 1)
			{
				position = tmp->position;
				nbr_moves = ft_lstsize(tmp) - tmp->position;
			}
		}
		tmp = tmp->next;
	}
	return (position + 1);
}

/*keep the langest increasment subsequence in the list a and push others to b*/
void	get_longest_increasement_lst(t_list **a, t_list **b)
{
	int		*lis_array;
	int		*non_lis_array;
	int		lis_array_len;
	int		non_lis_array_len;
	int		lst_size;

	lst_size = ft_lstsize(*a);
	lis_array_len = lis_len(lst_to_array(*a), lst_size);
	lis_array = lis(lst_to_array(*a), lst_size);
	non_lis_array = non_lis(lis_array, lis_array_len, lst_size);
	non_lis_array_len = lst_size - lis_array_len;
	// printf("\nlis\n");
	// int i = 0;
	// while (i < lis_array_len)
	// 	printf("| %d |",lis_array[i++]);
	// i = 0;
	// printf("\n non lis\n");
	// while (i < non_lis_array_len)
	// 	printf("| %d |",non_lis_array[i++]);
	// exit(0);
	// i = non_lis_array_len - 1;
	if (lst_size == 3 && !is_circular_sorted(*a))
		sa(a);
	while (!is_circular_sorted(*a))
	{
		fill_positions_of_a(a);
		if (is_in_array(non_lis_array, non_lis_array_len, (*a)->index))
		{
			pb(b, a);
		}
		else
		{
			if (nearest_index(non_lis_array,non_lis_array_len, *a) <= ft_lstsize(*a) / 2)
			{
				ra(a);
			}
			else
			{
				rra(a);
				// ft_putstr_fd("HERE", 1);
			}
		}
		// if (position_of_index(non_lis_array[i], *a) == 0)
		// {
		// 	pb(b, a);
		// 	i++;
		// }
		if (ft_lstsize(*a) == 3 && !is_circular_sorted(*a))
			sa(a);
	}
	// ft_putstr_fd("\nheeere end get lis\n",1);
	free(lis_array);
	free(non_lis_array);
}
