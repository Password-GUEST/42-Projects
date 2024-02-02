/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:14:12 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/22 17:07:57 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_cmd *lst, void (*del)(char**))
{
	if (lst)
	{
		if (del && lst->cmd)
			del(lst->cmd);
		if (lst->path)
			free(lst->path);
		free(lst);
	}
}
