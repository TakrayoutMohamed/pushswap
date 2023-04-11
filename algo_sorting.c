/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:01:22 by takra             #+#    #+#             */
/*   Updated: 2023/04/11 18:20:07 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpushswap.h"

void	del(int content)
{
	content = 0;
	(void)content;
}

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

int	get_right_position(t_list *lst, int value)
{
	t_list	*tmp;
	int		position;

	tmp = lst;
	position = 0;
	if (is_list_max(lst, value) || is_list_min(lst, value))
		return (index_of_list_max(lst) + 1);
	while (tmp != NULL && tmp->next != NULL)
	{
		position++;
		if (tmp->content < value && tmp->next->content > value)
			return (position);
		tmp = tmp->next;
	}
	if (position == ft_lstsize(lst) - 1)
		position = 0;
	return (position);
}

int	is_list_sorted(t_list *lst)
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

int	is_circular_sorted(t_list *lst)
{
	t_list	*tmp;
	int		nbr_of_grather_than;

	nbr_of_grather_than = 0;
	tmp = lst;
	if (!is_list_sorted(lst))
		while (tmp->next != NULL)
		{
			if (tmp->content > tmp->next->content)
				nbr_of_grather_than++;
			if (nbr_of_grather_than > 1)
				return (0);
			tmp = tmp->next;		
		}
	if (lst->content < tmp->content)
		return (0);
	return (1);
}
static void	print_lst(t_list *lst)
{
	// t_list	*tmp;

	// tmp = lst;
	while (lst != NULL)
	{
		printf("**%d** -> ",lst->content);
		lst = lst->next;
	}
	// tmp = NULL;
	printf("\n");
}

t_list *algo_sorting(t_list *a)
{
	t_list	*b;
	// t_list	*tmp;
	int		*lis_array;
	int		i;
	int		j;
	// int		lst_size;

	b = NULL;
	// tmp = a;
	i = 0;
	j = 0;
	lis_array = lis(lst_to_array(a), ft_lstsize(a));
	// i = 0;
	// while (i < 10)
	// {
	// 	printf("LIS[%d] = %d ",i , lis_array[i]);
	// 	i++;
	// }
	// exit(0);
		// printf("\n the lst size is %d\n", ft_lstsize(a));
	// lst_size = ft_lstsize(a);
	while (i < (ft_lstsize(a) + ft_lstsize(b)))
	{
		if (is_circular_sorted(a))
			break;
		if (i == lis_array[j] && j++ > -1)
			ra(&a);
		else
			pb(&b, &a);
		i++;
	}

	// i = 0;
	// while (i < 8)
	// {
	// 	printf("LIS[%d] = %d ",i , lis_array[i]);
	// 	i++;
	// }
	printf("\nright position = %d\n",get_right_position(a, b->content));
	// while (b != NULL)
	// {
		if (get_right_position(a, b->content) > (ft_lstsize(a) / 2))
			rra(&a);
		else
			ra(&a);
		// ra(&a);
	printf("\nright position = %d\n",get_right_position(a, b->content));

		if (get_right_position(a, b->content) > (ft_lstsize(a) / 2))
			rra(&a);
		else
			ra(&a);
		if (get_right_position(a, b->content) == 0)
			pa(&a, &b);


	// }
	ft_putendl_fd("\nlist a = ",1);
	print_lst(a);
	ft_putendl_fd("\nlist b = ",1);
	print_lst(b);
	// ft_putendl_fd("\nlist a = ",1);
	// print_lst(a);
	free(lis_array);
	ft_lstclear(&b, del);
	return (a);
}
