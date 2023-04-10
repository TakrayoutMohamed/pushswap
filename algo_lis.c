/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:26 by takra             #+#    #+#             */
/*   Updated: 2023/04/10 13:11:41 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libpushswap.h"

static int max_array(int array[],int arraylen)
{
	int	i;
	int max;

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

static int	*indexes_of_min_lis(int array[], int lis[], int arraylen)
{
	int	min_value;
	int	*indexes_lis;
	int	i;
	int lis_value;

	lis_value = 1;
	indexes_lis = (int *)malloc(sizeof(int) * max_array(lis, arraylen));
	while (lis_value <= max_array(lis, arraylen))
	{
		i = 0;
		while (i < arraylen)
		{
			min_value = array[i];
			if (lis[i++] == lis_value)
				break ;
		}
		i = -1;
		while (++i < arraylen)
		{
			// printf("\nlis[%d] = %d | lis_value = %d | array[%d] = %d | min_value = %d\n", i, lis[i], lis_value, i , array[i], min_value);
			if (lis[i] >= lis_value && array[i] <= min_value)
			{
				min_value = array[i];
				indexes_lis[lis_value - 1] = i;
				// printf("indexes_lis[%d] = %d\n",lis_value - 1, indexes_lis[lis_value - 1]);
			}
			if (lis[i] > lis_value)
				break ;
		}
		lis_value++;
	}
	// i = 0;
	// printf("\noooooooooooo\n");
	// while (i < 9)
	// {
	// 	printf("LIS[%d] = %d ",i , indexes_lis[i]);
	// 	i++;
	// }
	// printf("\noooooooooooo\n");
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
		j = 0;
		while (j < i)
		{
			if (array[i] > array[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
	}
	indexes_of_lis = indexes_of_min_lis(array, lis, arraylen);
	return (free(array), free(lis), indexes_of_lis);
}
