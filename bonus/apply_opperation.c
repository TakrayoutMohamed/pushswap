/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_opperation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:53:53 by takra             #+#    #+#             */
/*   Updated: 2023/05/20 02:23:27 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libchecker_bonus.h"

void	read_operations(t_list **lsta)
{
	ssize_t	readed;
	char	*buffer;
	t_list	*lstb;

	readed = 1;
	lstb = NULL;
	while (readed != -1)
	{
		readed = read(0, buffer, 4);
		if (readed != -1)
		{
			buffer[3] = '\0';
			apply_operations(lsta, &lstb, buffer);
		}
	}
}

void	apply_operations(t_list **lsta, t_list **lstb, char *operation)
{
	if (!strcmp("pa", operation))//need to change the strcmp to ft_strncmp
		pa_bonus(lsta, lstb);
	else if (!strcmp("pb", operation))
		pb_bonus(lstb, lsta);
	else if (!strcmp("sa", operation))
		sa_bonus(lsta);
	else if (!strcmp("sb", operation))
		sb_bonus(lstb);
	else if (!strcmp("ss", operation))
		ss_bonus(lsta, lstb);
	else if (!strcmp("ra", operation))
		ra_bonus(lsta);
	else if (!strcmp("rb", operation))
		rb_bonus(lstb);
	else if (!strcmp("rr", operation))
		rr_bonus(lsta, lstb);
	else if (!strcmp("rra", operation))
		rra_bonus(lsta);
	else if (!strcmp("rrb", operation))
		rrb_bonus(lstb);
	else if (!strcmp("rrr", operation))
		rrr_bonus(lsta, lstb);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
