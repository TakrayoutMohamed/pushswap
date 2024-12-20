/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libchecker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:38:23 by mohtakra          #+#    #+#             */
/*   Updated: 2023/05/20 09:45:45 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHECKER_BONUS_H
# define LIBCHECKER_BONUS_H
# include <fcntl.h>
# include "./operations/liboperation.h"
# include "../libpushswap.h"

int		read_operations(t_list **lst);
int		apply_operations(t_list **lsta, t_list **lstb, char *operation);

#endif