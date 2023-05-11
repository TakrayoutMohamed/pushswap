/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:26 by takra             #+#    #+#             */
/*   Updated: 2023/05/11 18:16:46 by takra            ###   ########.fr       */
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

int	still_has_next_values(int array[], int arraylen, int startindex)
{
	int	max_value;
	int	greater;
	int	i;

	i = startindex;
	max_value = max_array(array, arraylen);
	greater = array[i] + 1;
	while (i < arraylen)
	{
		if (array[i] == greater)
		{
			greater = array[i] + 1;
		}
		i++;
	}
	if (greater - 1 == max_value)
		return (1);
	return (0);
}

/*returns a pointer to an array that filled with indexes of
	minimal value of an increasement of an L.I.S*/
static int	*indexes_of_min_lis(int array[], int lis[], int arraylen)
{
	int	min_value;
	int	*indexes_lis;
	int	i;
	int	lis_value;

	lis_value = 0;
	indexes_lis = (int *)malloc(sizeof(int) * max_array(lis, arraylen));
	while (++lis_value <= max_array(lis, arraylen))
	{
		min_value = first_value(array, lis, lis_value, arraylen);
		i = -1;
		while (++i < arraylen)
		{
			if (lis[i] == lis_value && array[i] <= min_value)
			{
				if (still_has_next_values(lis, arraylen, i))
				{
					min_value = array[i];
					indexes_lis[lis_value - 1] = i;
				}
			}
		}
	}
	return (indexes_lis);
}

/*returns a pointer to an array that filled with indexes of
longest increasement subsequence of a given array */
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
	// i = 0;
	// while (i < arraylen)
	// 	printf("| %d |",lis[i++]);
	// exit(0);
	indexes_of_lis = indexes_of_min_lis(array, lis, arraylen);
	return (free(array), free(lis), indexes_of_lis);
}
