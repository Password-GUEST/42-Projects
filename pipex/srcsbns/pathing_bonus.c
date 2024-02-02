/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:21 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/22 17:10:13 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*ft_strccpy(const char *src, char c, char *cmd)
{
	size_t	index;
	size_t	longueur;
	char	*str;

	index = 0;
	longueur = 0;
	if (!src || ft_strichr((char *) src, c) < 0)
		return (NULL);
	str = malloc(ft_strichr((char *) src, c) + ft_strlen(cmd) + 2);
	if (!str)
		return (NULL);
	while (src[index] && src[index] != c)
	{
		str[index] = src[index];
		index++;
	}
	str[index++] = '/';
	while (cmd[longueur])
	{
		str[index++] = cmd[longueur++];
	}
	str[index] = '\0';
	return (str);
}

char	*ft_testpath(char *env, char *cmd)
{
	char	*rlpath;
	int		i;

	i = 0;
	rlpath = " ";
	while (rlpath)
	{
		rlpath = ft_strccpy(env, ':', cmd);
		if (access(rlpath, F_OK) == 0)
			return (rlpath);
		else if (rlpath)
			free(rlpath);
		i = ft_strichr(env, ':');
		i++;
		env += i;
	}
	return (NULL);
}

char	*pathcmd(char **env, char *cmd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			return (ft_testpath(env[i] + 5, cmd));
		i++;
	}
	return (NULL);
}
