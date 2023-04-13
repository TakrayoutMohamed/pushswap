/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:12:26 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/13 11:32:42 by takra            ###   ########.fr       */
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
	else if (!check_args(argv))
		ft_putendl_fd("Error an arg is not degit", 2);
	else
	{
		str_argvs = ft_joinargvs(argc, argv);
		matrix = ft_split(str_argvs, ' ');
		lst = matrix_to_lst(matrix);
		if (lst_duplcate_node(lst))
			return (printf("has duplacate values \n"), 2);
		if (!is_int(matrix, lst))
			return (printf("thier is number that not int \n"), 2);
		algo_sorting(&lst);
		free_matrix(matrix);
		free(str_argvs);
		ft_lstclear(&lst, del);
	}
	return (0);
}
