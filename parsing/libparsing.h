/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libparsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:50:26 by takra             #+#    #+#             */
/*   Updated: 2023/04/13 14:05:30 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPARSING_H
# define LIBPARSING_H
# include "./../libpushswap.h"

int	is_only_nbrs(char **str);
int	lst_duplicate_node(t_list *lst);
int	is_int(char **matrix, t_list *lst);
int	is_valid_list(char **matrix, char **argv, t_list *lst);

#endif