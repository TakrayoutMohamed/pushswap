/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_increasement_lst.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:13 by takra             #+#    #+#             */
/*   Updated: 2023/05/10 20:44:45 by takra            ###   ########.fr       */
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
	// i = 0;
	// printf("non lis\n");
	// while (i < lstsize - array_lis_len)
	// 	printf("| %d |",no_lis[i++]);
	// i = 0;
	// printf("\nlis\n");
	// while (i < array_lis_len)
	// 	printf("| %d |",lis_array[i++]);
	// exit(0);
	return (no_lis);
}


static void	fill_positions_of_a(t_list **a)
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

static int	position_of_index(int index, t_list *a)
{
	t_list	*tmp;
	int		position;

	tmp = a;
	position = 0;
	while (tmp != NULL)
	{
		if (index == tmp->index)
		{
			position = tmp->position;
			break ;
		}
		tmp = tmp->next;
	}
	// if (position == 0)
	// 	ft_putstr_fd("hola", 1);
	return (position);
}

/*keep the langest increasment subsequence in the list a and push others to b*/
void	get_longest_increasement_lst(t_list **a, t_list **b)
{
	int		*lis_array;
	int		*non_lis_array;
	int		array_lis_len;
	int		array_non_lis_len;
	int		i;

	i = 0;
	array_lis_len = lis_len(lst_to_array(*a), ft_lstsize(*a));
	lis_array = lis(lst_to_array(*a), ft_lstsize(*a));
	non_lis_array = non_lis(lis_array, array_lis_len, ft_lstsize(*a));
	array_non_lis_len = ft_lstsize(*a) - array_lis_len;
	// i = 0;
	// while (i < array_non_lis_len)
	// 	printf("| %d |",non_lis_array[i++]);
	// exit(0);
	if (ft_lstsize(*a) == 3 && !is_circular_sorted(*a))
		sa(a);
	while (!is_circular_sorted(*a) && i < array_non_lis_len)
	{
		fill_positions_of_a(a);
		// t_list *tmp = *a;
		// i = 0;
		// while (i < 5)
		// {
		// 	ft_putstr_fd("index of a =  ", 1);
		// 	ft_putnbr_fd((*a)->index, 1);
		// 	// *a = (*a)->next;
		// 	ra(a);
		// 	i++;
		// }
		// *a = tmp;
		// exit(0);
		if (is_in_array(non_lis_array, array_non_lis_len, (*a)->index))
		{
			pb(b, a);
			i++;
		}
		else
		{
			if (position_of_index(non_lis_array[i], *a) <= ft_lstsize(*a) / 2)
			{
				// exit(0);
				ra(a);
			}
			else if (position_of_index(non_lis_array[i], *a) > ft_lstsize(*a) / 2)
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
	free(lis_array);
	free(non_lis_array);
}
