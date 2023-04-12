/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:26 by takra             #+#    #+#             */
/*   Updated: 2023/04/12 17:59:13 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpushswap.h"

static int	max_array(int array[], int arraylen)
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

int	min_value_lis_index(int array[], int lis[], int lis_value, int arraylen)
{
	int	min_value;
	int	i;

	min_value = 2147483647;
	i = 0;
	while (i < arraylen)
	{
		if (lis[i] == lis_value && array[i] <= min_value)
		{
			min_value = array[i];
			return (min_value);
		}
		i++;
	}
	return (min_value);
}

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
		min_value = min_value_lis_index(array, lis, lis_value, arraylen);
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
