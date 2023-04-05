/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:49:39 by mohtakra          #+#    #+#             */
/*   Updated: 2022/10/27 07:51:19 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*memgoal;

	i = 0;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	memgoal = (void *)malloc(count * size);
	if (!memgoal)
		return (NULL);
	while (i < count * size)
	{
		memgoal[i] = 0;
		i++;
	}
	return (memgoal);
}
