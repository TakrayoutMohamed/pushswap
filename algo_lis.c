/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:26 by takra             #+#    #+#             */
/*   Updated: 2023/04/10 08:14:09 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpushswap.h"

int	lis(t_list *lst)
{
	int	*lis;
	int	max;
	t_list	*tmp1;
	t_list	*tmp2;
	int	i;
	int	j;

	i = 0;
	max = 0;
	lis = (int *)malloc (sizeof(int) * ft_lstsize(lst));
	/*fill all the table lis with 1 as start*/
	while (i < ft_lstsize(lst))
		lis[i++] = 1;
	i = 0;
	tmp2 = lst;
	while (lst != NULL)
	{
		tmp1 = tmp2;
		j = 0;
		while (tmp1 != NULL && tmp1->content != lst->content)
		{
			// ft_putstr_fd("[[[here]]]",1);
			if (lst->content > tmp1->content && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			tmp1 = tmp1->next;
			j++;
		}
		i++;
		lst = lst->next;
	}
	lst = tmp2;
	/*pick the maximum of all lis values*/
	i = 0;
	while (i < ft_lstsize(lst))
	{
		if (max < lis[i])
			max = lis[i];
		i++;
	}

	free(lis);
	return (max);
}
