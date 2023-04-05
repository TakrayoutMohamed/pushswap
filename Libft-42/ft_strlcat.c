/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:32:45 by mohtakra          #+#    #+#             */
/*   Updated: 2022/10/30 18:24:48 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t d)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	if (!dst && !d)
		return (ft_strlen(src) + d);
	i = 0;
	dst_size = ft_strlen((const char *)dst);
	src_size = ft_strlen(src);
	if (dst_size < d)
	{
		while (*dst)
			dst++;
		while (*src && dst_size + i < d - 1)
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		*dst = '\0';
		return (dst_size + src_size);
	}
	return (src_size + d);
}
