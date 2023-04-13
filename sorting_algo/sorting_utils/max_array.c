/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:12:31 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:18:40 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return the max of an array*/
int	max_array(int array[], int arraylen)
{
	int	i;
	int	max;

	i = 0;
	max = array[i];
	while (i < arraylen)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
