/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_less_nbr_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:54:32 by takra             #+#    #+#             */
/*   Updated: 2023/05/09 19:20:59 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

int	get_less_nbr_moves(t_list **lst)
{
	int		moves_to_position;
	t_list	*tmp;

	tmp = *lst;
	moves_to_position = tmp->position;
	while (tmp != NULL)
	{
		if (tmp->position < moves_to_position)
			moves_to_position = tmp->position;
		tmp = tmp->next;
	}
	return (moves_to_position);
}
