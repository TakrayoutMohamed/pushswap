/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:12:11 by mohtakra          #+#    #+#             */
/*   Updated: 2022/10/28 04:18:00 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*target;
	size_t	i;

	i = 0;
	target = 0;
	while (n > i)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			target = (char *)(s + i);
			break ;
		}
		i++;
	}
	return (target);
}
