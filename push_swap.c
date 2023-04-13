/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:12:26 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/13 14:13:46 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	main(int argc, char **argv)
{
	char	*str_argvs;
	char	**matrix;
	t_list	*lst;

	if (argc == 1)
		return (0);
	else
	{
		str_argvs = ft_joinargvs(argc, argv);
		matrix = ft_split(str_argvs, ' ');
		lst = matrix_to_lst(matrix);
		if (!is_valid_list(matrix, argv, lst))
		{
			ft_putstr_fd("Error\n", 2);
		}
		else
		{
			algo_sorting(&lst);
		}
		free_matrix(matrix);
		free(str_argvs);
		ft_lstclear(&lst, del);
	}
	return (0);
}
