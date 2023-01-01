/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:11:53 by mohtakra          #+#    #+#             */
/*   Updated: 2022/12/26 20:04:45 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
#define LIBPUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
	int	check_args(char **str);
	int	ft_isdigit(int c);
	void	ft_putendl_fd(char *s, int fd);
	void	ft_putchar_fd(char c, int fd);
	void	ft_putstr_fd(char *c, int fd);

	typedef struct s_list
	{
		int				content;
		struct s_list	*next;
	} t_list;
	
	t_list	*ft_lstnew(int	content);
	void	ft_lstadd_front(t_list **lst, t_list *new);
	void	ft_lstadd_back(t_list **lst, t_list *new);
	void	ft_lstdelone(t_list *lst, void (*del)(void *));
#endif