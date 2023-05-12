/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:13:49 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/12 01:13:56 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libsortalgo.h"

/*returns a pointer to an array filled with indexes of nodes that not a part
of longest increasement subsequence array (lis) */
int	*non_lis(int lis_array[], int array_lis_len, int lstsize)
{
	int	*no_lis;
	int	i;
	int	j;

	i = 0;
	j = 0;
	no_lis = (int *)malloc(sizeof(int) * (lstsize - array_lis_len));
	while (i < lstsize && j < lstsize - array_lis_len)
	{
		if (!is_in_array(lis_array, array_lis_len, i))
		{
			no_lis[j] = i;
			j++;
		}
		i++;
	}
	return (no_lis);
}
