/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:00:55 by takra             #+#    #+#             */
/*   Updated: 2023/05/12 22:58:10 by mohtakra         ###   ########.fr       */
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

/*return true if the given char is a sign + or - */
static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

/*return true if the given matrix countain only chars that is in range of int*/
int	is_int(char **matrix, t_list *lst)
{
	int	j;
	int	minus;

	while (*matrix && lst)
	{
		j = 0;
		minus = 0;
		if (ft_is_sign((*matrix)[0]))
		{
			j++;
			if ((*matrix)[0] == '-')
				minus = 1;
		}
		while ((*matrix)[j] == '0' && (*matrix)[j + 1] != '\0')
				j++;
		if ((int)ft_strlen((*matrix) + j) + minus != ft_nbrlen(lst->content))
			return (0);
		lst = lst->next;
		matrix++;
	}
	return (1);
}
