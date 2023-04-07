/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:11:53 by mohtakra          #+#    #+#             */
/*   Updated: 2023/04/07 16:27:20 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
#define LIBPUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "./Libft-42/libft.h"
# include "./sorting_operations/libsorting.h"
	int		check_args(char **str);
	char	*ft_joinargvs(int argc, char **argv);
	char	*ft_strtrim_free(char *str, char *set);
	t_list	*matrix_to_lst(char **matrix);
	int		lst_duplcate_node(t_list *lst);
	int		is_int(char **matrix, t_list *lst);
	void	free_matrix(char **matrix);

#endif