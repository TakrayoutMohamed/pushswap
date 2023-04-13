/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:26 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 15:22:25 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*return the first value of an array while lis of its index equal lis_value*/
static int	first_value(int array[], int lis[], int lis_value, int arraylen)
{
	int	value;
	int	i;

	value = 2147483647;
	i = 0;
	while (i < arraylen)
	{
		if (lis[i] == lis_value)
		{
			value = array[i];
			return (value);
		}
		i++;
	}
	return (value);
}

/*returns a pointer to an array that filled with indexes of*/
/*minimal value of an increasement of an L.I.S*/
static int	*indexes_of_min_lis(int array[], int lis[], int arraylen)
{
	int	min_value;
	int	*indexes_lis;
	int	i;
	int	lis_value;

	lis_value = 1;
	indexes_lis = (int *)malloc(sizeof(int) * max_array(lis, arraylen));
	while (lis_value <= max_array(lis, arraylen))
	{
		min_value = first_value(array, lis, lis_value, arraylen);
		i = -1;
		while (++i < arraylen)
		{
			if (lis[i] == lis_value && array[i] <= min_value)
			{
				min_value = array[i];
				indexes_lis[lis_value - 1] = i;
			}
			if (lis[i] > lis_value)
				break ;
		}
		lis_value++;
	}
	return (indexes_lis);
}

/*returns a pointer to an array that filled with indexes of*/
/*longest increasement subsequence of a given array */
int	*lis(int array[], int arraylen)
{
	int	*lis;
	int	*indexes_of_lis;
	int	i;
	int	j;

	i = 0;
	lis = (int *)malloc (sizeof(int) * arraylen);
	if (!lis)
		return (free(array), NULL);
	while (i < arraylen)
		lis[i++] = 1;
	i = -1;
	while (++i < arraylen)
	{
		j = -1;
		while (++j < i)
			if (array[i] > array[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
	indexes_of_lis = indexes_of_min_lis(array, lis, arraylen);
	return (free(array), free(lis), indexes_of_lis);
}