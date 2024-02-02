/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:37:59 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/22 20:24:55 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/*
 ERR CODES : 
	PIPE : -1
	FORK : -2
	DUP  : -3
	FD	 : -4
*/
# include "../libft/libft.h"
/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <limits.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

typedef struct s_gnrl
{
	int		*pid;
	int		fd[2];
	int		fda[2];
	int		fdw[2];
}	t_gnrl;

// parse.c
void	ft_parse(int argc, char **argv, t_cmd **fcmd, char **env);

// pathing.c
char	*pathcmd(char **env, char *cmd);

// main.c
void	ft_freetab(char **cmd);

#endif