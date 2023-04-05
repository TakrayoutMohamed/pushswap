/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:24:14 by mohtakra          #+#    #+#             */
/*   Updated: 2022/10/11 12:24:20 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*target;
	int		str_len;

	str_len = ft_strlen(s);
	target = 0;
	while (*s)
		s++;
	while (str_len-- >= 0)
	{
		if (*s == (char) c)
		{
			target = s;
			break ;
		}
		s--;
	}
	return (target);
}
