/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:00:55 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 22:21:06 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libparsing.h"

/*return how many chars in a nbr */
static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*return true if the given matrix countain only chars that is in range of int*/
int	is_int(char **matrix, t_list *lst)
{
	while (*matrix && lst)
	{
		if ((int)ft_strlen(*matrix) != ft_nbrlen(lst->content))
		{
			if (*matrix[0] != '+')
				return (0);
		}
		lst = lst->next;
		matrix++;
	}
	return (1);
}
