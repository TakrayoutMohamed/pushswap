/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:12:54 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/12 01:13:01 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return true if the value exist in given array 
that have a lenght of array_len*/
int	is_in_array(int array[], int array_len, int value)
{
	int	i;

	i = 0;
	while (i < array_len)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}
