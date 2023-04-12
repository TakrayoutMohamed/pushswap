/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:12:26 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/12 14:50:42 by takra            ###   ########.fr       */
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

static void del(int content)
{
	content = 0;
	(void)content;
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
		// free(str_argvs);
		// str_argvs = ft_strdup("1 2 3 4 5 6 7 8  9 0");
		matrix = ft_split(str_argvs, ' ');
		lst = matrix_to_lst(matrix);
		printf("\n ||%s||\n", str_argvs);
		if (lst_duplcate_node(lst))
			return (printf("has duplacate values \n"), 0);
		if (!is_int(matrix, lst))
			return (printf("thier is number that not int \n"), 0);
		algo_sorting(&lst);
		print_lst(lst);
		free_matrix(matrix);
		free(str_argvs);
		ft_lstclear(&lst, del);
	}
	return (0);
}
