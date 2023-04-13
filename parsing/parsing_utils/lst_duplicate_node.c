/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_duplicate_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:02:55 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 13:42:31 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libparsing.h"

/*return true if thier is two nodes with the same content value*/
int	lst_duplicate_node(t_list *lst)
{
	t_list	*temp;
	int		value;

	while (lst != NULL)
	{
		temp = lst;
		value = temp->content;
		while (temp != NULL)
		{
			temp = temp->next;
			if (temp != NULL && temp->content == value)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}