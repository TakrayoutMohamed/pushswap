/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:12:26 by mohtakra          #+#    #+#             */
/*   Updated: 2022/12/26 18:10:28 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		ft_putendl_fd("No stack to sort", 1);
	else if (!check_args(argv))
		ft_putendl_fd("Error an arg is not degit", 1);
	else
		ft_putendl_fd("ok no error", 1);
	return (0);
}