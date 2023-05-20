/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:50:44 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 08:01:24 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./liboperation.h"

void	rb_bonus(t_list **lst)
{
	if (ft_lstsize(*lst) > 1)
	{
		rotate_list(lst);
	}
}