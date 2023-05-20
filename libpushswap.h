/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:11:53 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/20 09:46:46 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "./Libft-42/libft.h"
# include "./operations/liboperation.h"
# include "./parsing/libparsing.h"
# include "./bonus/libchecker_bonus.h"
# include "./sorting_algo/libsortalgo.h"

void	del(int content);
char	*ft_joinargvs(int argc, char **argv);
t_list	*matrix_to_lst(char **matrix);
int		*lst_to_array(t_list *lst);
void	free_matrix(char **matrix);

#endif
