/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:47:08 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 00:24:06 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	rra(t_list **lst)
{
	if (ft_lstsize(*lst) > 1)
	{
		revers_rotate_list(lst);
		ft_putendl_fd("rra", 1);
	}
}
