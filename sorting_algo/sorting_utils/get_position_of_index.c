/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_of_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:25:31 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/19 00:29:25 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return the position that the considered as prior number should be in at a*/
int	get_position_of_index(t_list **lst, int index)
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
