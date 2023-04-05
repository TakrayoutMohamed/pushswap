/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:00:28 by mohtakra          #+#    #+#             */
/*   Updated: 2022/10/23 00:26:01 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*target;

	i = 0;
	target = NULL;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && *haystack)
	{
		target = (char *) haystack;
		j = 0;
		while (i + j < len && needle[j] == haystack[j] && needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return (target);
		else
			target = NULL;
		i++;
		haystack++;
	}
	return (target);
}
