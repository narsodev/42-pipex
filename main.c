/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:32:48 by ngonzale          #+#    #+#             */
/*   Updated: 2022/08/17 01:30:28 by narso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <fcntl.h>

void	ft_print_command(void *content)
{
	t_command	*command;
	size_t		i;

	command = (t_command *) content;
	i = 0;
}

void	ft_manage_command(t_list *commands, char **envp)
{
	t_command *command;

	command = (t_command *) commands;
	ft_exec(command, envp);
}

void	ft_exec_commands(t_list *commands, char **envp)
{
	t_command	*command;

	while (commands)
	{
		command = (t_command *) commands->content;
		ft_printf("path: %s, fd: %d\n", command->path, command->fd_read);
		if (command->type == FILE_READ)
			((t_command *)commands->next->content)->fd_read = open(command->path, O_RDONLY);
		else if (command->type == COMMAND)
			ft_manage_command(commands, envp);
		commands = commands->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_list *commands;

	if (argc != 5)
	{
		ft_printf("five args required!\n");
		return (1);
	}

	commands = ft_parse_args(argc, argv);
	ft_exec_commands(commands, envp);

}
