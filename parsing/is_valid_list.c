/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:50:36 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 22:22:55 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libparsing.h"

/*return true if the args given args are accepted :  */
/* begits, space ,non douplicate  and intigers interval*/
int	is_valid_list(char **matrix, char **argv, t_list *lst)
{
	if (!is_only_nbrs(argv))
		return (0);
	if (lst_duplicate_node(lst))
		return (0);
	if (!is_int(matrix, lst))
		return (0);
	return (1);
}
