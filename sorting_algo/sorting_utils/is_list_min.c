/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_list_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:53:37 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:18:27 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

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
