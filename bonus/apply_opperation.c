/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_opperation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:53:53 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 10:56:12 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libchecker_bonus.h"

int	read_operations(t_list **lsta)
{
	ssize_t	readed;
	char	*buffer;
	t_list	*lstb;

	readed = 1;
	lstb = NULL;
	buffer = (char *)malloc(sizeof(char) * 5);
	while (readed != -1)
	{
		readed = read(0, buffer, 5);
		if (readed != -1)
		{
			buffer[readed] = '\0';
			if (*buffer == '\0')
				break ;
			if (!apply_operations(lsta, &lstb, buffer))
			{
				ft_putstr_fd("Error\n", 2);
				return (free(buffer), ft_lstclear(&lstb, del), 0);
			}
		}
	}
	if (is_sorted_list(*lsta) && ft_lstsize(lstb) == 0)
		return (free(buffer), ft_putstr_fd("OK\n", 1), 1);
	return (free(buffer), ft_lstclear(&lstb, del), ft_putstr_fd("KO\n", 1), 0);
}

int	apply_operations(t_list **lsta, t_list **lstb, char *operation)
{
	if (!ft_strncmp("pa\n", operation, 4))
		pa_bonus(lsta, lstb);
	else if (!ft_strncmp("pb\n", operation, 4))
		pb_bonus(lstb, lsta);
	else if (!ft_strncmp("sa\n", operation, 4))
		sa_bonus(lsta);
	else if (!ft_strncmp("sb\n", operation, 4))
		sb_bonus(lstb);
	else if (!ft_strncmp("ss\n", operation, 4))
		ss_bonus(lsta, lstb);
	else if (!ft_strncmp("ra\n", operation, 4))
		ra_bonus(lsta);
	else if (!ft_strncmp("rb\n", operation, 4))
		rb_bonus(lstb);
	else if (!ft_strncmp("rr\n", operation, 4))
		rr_bonus(lsta, lstb);
	else if (!ft_strncmp("rra\n", operation, 5))
		rra_bonus(lsta);
	else if (!ft_strncmp("rrb\n", operation, 5))
		rrb_bonus(lstb);
	else if (!ft_strncmp("rrr\n", operation, 5))
		rrr_bonus(lsta, lstb);
	else
		return (0);
	return (1);
}
