/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:25:14 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/13 03:31:18 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_cmd **alst, t_cmd *new)
{
	t_cmd	*last;

	if (*alst)
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
	else
		*alst = new;
}
