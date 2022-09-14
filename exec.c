/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:31:44 by narso             #+#    #+#             */
/*   Updated: 2022/08/17 01:30:49 by narso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void	ft_exec(t_command *command, char **envp)
{
	ft_printf("path: %s, name: %s\n", command->path, command->args[0]);
	execve(command->path, command->args, envp);
	perror("execve");
}
