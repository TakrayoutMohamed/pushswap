/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:05 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 00:24:10 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	rrb(t_list **lst)
{
	if (ft_lstsize(*lst) > 1)
	{
		revers_rotate_list(lst);
		ft_putendl_fd("rrb", 1);
	}
}
