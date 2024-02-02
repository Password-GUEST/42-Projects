/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:19 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/22 19:41:13 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_freetab(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	ft_parse(int argc, char **argv, t_cmd **fcmd, char **env)
{
	t_cmd	*tmp;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		ft_lstadd_back(fcmd, ft_lstnew(ft_split(argv[i], ' '), i));
		i++;
	}
	tmp = *fcmd;
	while (tmp)
	{
		if (tmp->cmd[0])
			tmp->path = pathcmd(env, tmp->cmd[0]);
		else
			tmp->path = NULL;
		tmp = tmp->next;
	}
}
