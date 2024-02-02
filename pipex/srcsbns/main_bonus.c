/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:14 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/22 21:11:23 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"
#include <errno.h>

void	ft_errors(int errcd, char *cmd)
{
	if (!cmd)
		cmd = "(null)";
	if (errcd == -1)
		perror(NULL);
	else if (errcd == -2)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : ", 2);
		perror(NULL);
	}
	else if (errcd == -3)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : CMD NOT FOUND\n", 2);
	}
	else if (errcd == -4)
		ft_putstr_fd("ERROR : ARGS INVALID\n", 2);
	exit(errcd);
}

void	ft_begin(int argc, char **argv, t_gnrl	*pidfd)
{
	if (argc < 5)
		ft_errors(-4, "");
	pidfd->fdw[0] = open(argv[1], O_RDONLY);
	if (pidfd->fdw[0] < 0 || pidfd->fdw[0] > OPEN_MAX)
	{
		ft_errors(-2, argv[1]);
		close(pidfd->fdw[0]);
		pidfd->fdw[0] = open("/dev/null", O_RDONLY);
	}
	pidfd->fdw[1] = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 420);
	if (pidfd->fdw[1] < 0 || pidfd->fdw[1] > OPEN_MAX)
	{
		close(pidfd->fdw[0]);
		ft_errors(-2, argv[argc - 1]);
	}
}

void	ft_end(t_gnrl pidfd, t_cmd *cmd, int j)
{
	int	i;

	i = 0;
	close(pidfd.fd[0]);
	close(pidfd.fd[1]);
	while (i <= j)
		waitpid(pidfd.pid[i++], NULL, 0);
	ft_lstclear(&cmd, &ft_freetab);
	exit(0);
}

void	ft_idk(t_gnrl pidfd, t_cmd **cmd, char **env, int *i)
{
	*i = 0;
	dup2(pidfd.fdw[0], 0);
	while ((*cmd)->next)
	{
		pipe(pidfd.fd);
		pidfd.pid[*i] = fork();
		if (pidfd.pid[*i] < 0)
			ft_errors(-1, (*cmd)->cmd[0]);
		if (pidfd.pid[*i] == 0)
		{
			close(pidfd.fd[0]);
			dup2(pidfd.fd[1], 1);
			execve((*cmd)->path, (*cmd)->cmd, NULL);
			ft_errors(-3, (*cmd)->cmd[0]);
		}
		else
		{
			close(pidfd.fd[1]);
			dup2(pidfd.fd[0], 0);
		}
		(*cmd) = (*cmd)->next;
		(*i)++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_cmd	*fcmd;
	t_gnrl	pidfd;
	int		i;

	errno = 0;
	cmd = NULL;
	ft_begin(argc, argv, &pidfd);
	ft_parse(argc, argv, &cmd, env);
	fcmd = cmd;
	pidfd.pid = (int *)malloc(sizeof(int) * ft_lstsize(cmd) + 1);
	ft_idk(pidfd, &cmd, env, &i);
	pidfd.pid[i] = fork();
	if (pidfd.pid[i] == 0)
	{
		close(pidfd.fd[0]);
		dup2(pidfd.fdw[1], 1);
		execve(cmd->path, cmd->cmd, NULL);
		ft_errors(-3, cmd->cmd[0]);
	}
	ft_end(pidfd, fcmd, i);
}
