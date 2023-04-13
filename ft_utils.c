/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:11:20 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/13 12:02:28 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

/*return a pointer to str of joined content of the double pointer argv*/
char	*ft_joinargvs(int argc, char **argv)
{
	char	*str_argvs;
	char	*temp;
	int		i;

	i = 0;
	str_argvs = NULL;
	while (argc > 0)
	{
		temp = str_argvs;
		str_argvs = ft_strjoin(str_argvs, " ");
		free(temp);
		temp = str_argvs;
		str_argvs = ft_strjoin(str_argvs, argv[++i]);
		free(temp);
		argc--;
	}
	return (str_argvs);
}

char	*ft_strtrim_free(char *str, char *set)
{
	char	*temp;

	temp = str;
	str = ft_strtrim(str, set);
	free(temp);
	return (str);
}

/*return a list that's filled by the values of the matrix converted to int*/
t_list	*matrix_to_lst(char **matrix)
{
	t_list	*lst;
	t_list	*temp;

	lst = ft_lstnew(ft_atoi(*matrix++));
	while (*matrix)
	{
		temp = ft_lstnew(atoi(*matrix++));
		ft_lstadd_back(&lst, temp);
	}
	return (lst);
}

/*used to free a double pointer char proprly*/
void	free_matrix(char **matrix)
{
	char	**temp;

	temp = matrix;
	while (*matrix)
	{
		free(*matrix);
		matrix++;
	}
	matrix = temp;
	free(matrix);
}

/*return a pointer to an array that filled with lst's values*/
int	*lst_to_array(t_list *lst)
{
	t_list	*temp;
	int		*lst_array;
	int		i;

	lst_array = (int *) malloc(sizeof(int) * ft_lstsize(lst));
	if (!lst_array)
		return (NULL);
	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		lst_array[i++] = temp->content;
		temp = temp->next;
	}
	temp = NULL;
	return (lst_array);
}
