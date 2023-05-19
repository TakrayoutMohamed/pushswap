/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libchecker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:38:23 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/19 23:43:02 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../Libft-42/libft.h"
# include "../operations/liboperation.h"
# include "../parsing/libparsing.h"

void	del(int content);
char	*ft_joinargvs(int argc, char **argv);
t_list	*matrix_to_lst(char **matrix);
int		*lst_to_array(t_list *lst);
void	free_matrix(char **matrix);

#endif