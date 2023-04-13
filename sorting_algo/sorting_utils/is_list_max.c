/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_list_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:53:59 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 14:58:48 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

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
