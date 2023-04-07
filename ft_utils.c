/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:11:20 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/07 09:40:14 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	is_int(char **matrix, t_list *lst)
{
	while (*matrix && lst)
	{
		if ((int)ft_strlen(*matrix) != ft_nbrlen(lst->content))
			return (0);
		lst = lst->next;
		matrix++;
	}
	return (1);
}

int	check_args(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && !ft_is_space(str[i][j]))
			{
				if (ft_is_sign(str[i][j]) && ft_is_sign(str[i][j - 1]))
				{
					return (0);
				}
				else if (!ft_is_sign(str[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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

int	lst_duplcate_node(t_list *lst)
{
	t_list	*temp;
	int		value;

	while (lst != NULL)
	{
		temp = lst;
		value = temp->content;
		while (temp != NULL)
		{
			temp = temp->next;
			if (temp != NULL && temp->content == value)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}
