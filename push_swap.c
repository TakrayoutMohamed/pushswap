/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:12:26 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/15 09:25:24 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"


void	print_matrix(char **matrix)
{
	int	i = 0;
	int j;

	ft_putchar_fd('{', 1);
	while (matrix[i])
	{
		j = 0;
		ft_putchar_fd('[', 1);
		while (matrix[i][j])
		{
			ft_putchar_fd(matrix[i][j], 1);
			j++;
		}
		ft_putchar_fd(']', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('}', 1);
}

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
