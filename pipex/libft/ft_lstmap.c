/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:39:15 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/19 23:00:43 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd	*ft_lstmap(t_cmd *lst, void *(*f)(void *), void (*del)(void *))
{
	t_cmd	*new;
	t_cmd	*fl;

	fl = NULL;
	while (lst)
	{	
		new = ft_lstnew(f(lst->cmd), 0);
		if (!new->cmd)
			del(new->cmd);
		lst = lst->next;
		ft_lstadd_back(&fl, new);
	}
	return (fl);
}
