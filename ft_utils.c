/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:11:20 by mohtakra          #+#    #+#             */
/*   Updated: 2022/12/26 18:23:02 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	check_args(char **str)
{
	str++;
	while (*str)
	{
		while (**str)
		{
			if (!ft_isdigit(**str))
				return (0);
			(*str)++;
		}
		str++;
	}
	return (1);
}