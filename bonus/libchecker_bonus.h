/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libchecker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:38:23 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/20 02:11:47 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHECKER_BONUS_H
# define LIBCHECKER_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../Libft-42/libft.h"
# include "./operations/liboperation.h"
# include "../parsing/libparsing.h"
# include "../sorting_algo/libsortalgo.h"

void	read_operations(t_list **lst);
void	apply_operations(t_list **lsta, t_list **lstb, char *operation);

#endif