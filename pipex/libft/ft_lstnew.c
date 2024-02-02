/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:05:01 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/22 19:42:40 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd	*ft_lstnew(char **content, int i)
{
	t_cmd		*new;

	new = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->cmd = content;
	new->pos = i;
	return (new);
}
