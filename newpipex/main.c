/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:21:13 by narso             #+#    #+#             */
/*   Updated: 2022/09/20 20:32:43 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void	ft_close_command_fd(void *content)
{
	t_command	*command;

	command = (t_command *) content;
	if (command->type != TYPE_COMMAND && command->fd_opened > 0)
		close(command->fd_opened);
}

int	main(int argc, char **argv, char **envp)
{
	t_list		*commands;
	t_list		*cur_command;
	t_command	*command;
	char		*env_path;

	ft_check_args(argc);
	env_path = ft_get_env_path(envp);
	commands = ft_get_commands(argv + 1, argc - 1, env_path);
	if (!commands)
		return (EXIT_FAILURE);
	cur_command = commands;
	while (cur_command)
	{
		command = (t_command *) cur_command->content;
		ft_execute_command(cur_command, envp);
		cur_command = cur_command->next;
	}
	ft_lstiter(commands, ft_close_command_fd);
	ft_lstclear(&commands, ft_free_command);
	return (EXIT_SUCCESS);
}
