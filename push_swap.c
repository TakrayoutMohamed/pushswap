/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:12:26 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/05 11:33:19 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		printf("**%d** -> ",lst->content);
		lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}
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
		ft_putendl_fd("No stack to sort", 2);
	else if (!check_args(argv))
		ft_putendl_fd("Error an arg is not degit", 2);
	else
	{
		str_argvs = ft_joinargvs(argc, argv);
		matrix = ft_split(str_argvs, ' ');
		lst = matrix_to_lst(matrix);
		printf("\n ||%s||\n", str_argvs);
		if (lst_duplcate_node(lst))
			return (printf("has duplacate values \n"), 0);
		// print_matrix(matrix);
		// ft_putendl_fd("\n", 1);
		print_lst(lst);
		lst->next->content = 32;
		print_lst(lst);

	}
	return (0);
}
