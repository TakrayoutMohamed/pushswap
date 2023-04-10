/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:01:22 by takra             #+#    #+#             */
/*   Updated: 2023/04/10 13:28:04 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpushswap.h"

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

void algo_sorting(t_list *a)
{
	t_list	*b;
	// t_list	*tmp;
	int		*lis_array;
	int		i;
	int		j;
	int		lst_size;

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
	lst_size = ft_lstsize(a);
	while (i < lst_size)
	{
		if (i == lis_array[j])
		{
			j++;
			ra(&a);
		}
		else
			pb(&b, &a);
		// ft_putendl_fd("{{ here }}",1);
		// printf("\n%d\n", i);
		// tmp = tmp->next;
		i++;
	}

	// i = 0;
	// while (i < 8)
	// {
	// 	printf("LIS[%d] = %d ",i , lis_array[i]);
	// 	i++;
	// }
	ft_putendl_fd("\nlist a = ",1);
	print_lst(a);
	ft_putendl_fd("\nlist b = ",1);
	print_lst(b);
	ft_putendl_fd("\nlist a = ",1);
	print_lst(a);

}
