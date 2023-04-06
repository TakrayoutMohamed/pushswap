/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:57:16 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/05 13:33:20 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int))
{
	t_list	*result;
	t_list	*temp;

	if (!f || !del || !lst)
		return (NULL);
	result = ft_lstnew(*(int *)f(lst->content));
	if (!result)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(*(int *)f(lst->content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	temp = NULL;
	return (result);
}
