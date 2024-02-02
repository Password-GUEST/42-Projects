/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:14 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/11/27 21:23:27 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errors(int errcd, char *cmd)
{
	if (!cmd)
		cmd = "(null)";
	if (errcd == -1)
		ft_putstr_fd("ERROR : FORK CREATE FAILED\n", 2);
	else if (errcd == -2)
		ft_putstr_fd("ERROR : CAN'T OPEN FILE (FD OR ACCESS)\n", 2);
	else if (errcd == -3)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : CMD NOT FOUND\n", 2);
	}
	else if (errcd == -4)
		ft_putstr_fd("ERROR : ARGS INVALID\n", 2);
	else if (errcd == -5)
		ft_putstr_fd("ERROR : OUTFILE FD INVALID\n", 2);
	exit(errcd);
}

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

void	ft_end(t_gnrl pidfd, t_cmd **cmd)
{
	close(pidfd.fd[0]);
	close(pidfd.fd[1]);
	waitpid(pidfd.pida, NULL, 0);
	exit(0);
}

void	ft_idk(t_gnrl pidfd, t_cmd *cmd, char **env)
{
	if (pidfd.pida == 0)
	{
		dup2(pidfd.fdw[1], 1);
		close(pidfd.fd[1]);
		dup2(pidfd.fdw[0], 0);
		if (cmd->cmd[0])
			dup2(pidfd.fd[0], 0);
		close(pidfd.fd[0]);
		if (cmd->next->path)
			execve(cmd->next->path, cmd->next->cmd, NULL);
		ft_errors(-3, cmd->next->cmd[0]);
	}
	pidfd.pidb = fork();
	if (pidfd.pidb < 0)
		ft_errors(-1, cmd->cmd[0]);
	if (pidfd.pidb == 0)
	{
		dup2(pidfd.fdw[0], 0);
		close(pidfd.fd[0]);
		dup2(pidfd.fd[1], 1);
		close(pidfd.fd[1]);
		execve(cmd->path, cmd->cmd, NULL);
		ft_errors(-3, cmd->cmd[0]);
	}
	waitpid(pidfd.pidb, NULL, 0);

}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_gnrl	pidfd;

	if (argc != 5)
		ft_errors(-4, "");
	pidfd.fdw[0] = open(argv[1], O_RDONLY);
	if (pidfd.fdw[0] < 0 || pidfd.fdw[0] > OPEN_MAX)
		ft_errors(-2, "");
	pidfd.fdw[1] = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 420);
	if (pidfd.fdw[1] < 0 || pidfd.fdw[1] > OPEN_MAX)
	{
		close(pidfd.fdw[0]);
		ft_errors(-5, "");
	}
	cmd = NULL;
	ft_parse(argc, argv, &cmd, env);
	pipe(pidfd.fd);
	pidfd.pida = fork();
	if (pidfd.pida < 0)
		ft_errors(-1, cmd->cmd[0]);
	ft_idk(pidfd, cmd, env);
	ft_end(pidfd, &cmd);
	ft_lstclear(&cmd, &ft_freetab);
}
