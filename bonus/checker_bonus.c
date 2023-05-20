/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:36:43 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/20 10:49:38 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libchecker_bonus.h"

int	is_null(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_null(argv[i]))
			return (0);
		i++;
	}
	return (1);
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
		if (!check_args(argc, argv) || !is_valid_list(matrix, argv, lst))
			ft_putstr_fd("Error\n", 2);
		else
		{
			read_operations(&lst);
		}
		free_matrix(matrix);
		free(str_argvs);
		ft_lstclear(&lst, del);
	}
	return (0);
}
