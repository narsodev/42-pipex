/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:16:53 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/20 20:31:04 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "pipex.h"

void	ft_exec_child(t_command *command, int ptc[2], int ctp[2], char **envp)
{
	close(ptc[1]);
	close(ctp[0]);
	if (command->fd_input > 1)
		dup2(command->fd_input, STDIN_FILENO);
	else
		dup2(ptc[0], STDIN_FILENO);
	if (command->fd_output > 1)
		dup2(command->fd_output, STDOUT_FILENO);
	else
		dup2(ctp[1], STDOUT_FILENO);
	execve(command->path, command->args, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	ft_exec(t_command *command, char **envp)
{
	pid_t	pid;
	int		ptc[2];
	int		ctp[2];

	if (pipe(ptc) == -1)
		return (-1);
	if (pipe(ctp) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_exec_child(command, ptc, ctp, envp);
	else
	{
		close(ptc[1]);
		close(ptc[0]);
		close(ctp[1]);
	}
	return (ctp[0]);
}
