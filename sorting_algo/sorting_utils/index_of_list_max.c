/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of_list_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:05:55 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:08:17 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

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
