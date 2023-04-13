/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_right_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:06:17 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:08:36 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

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
