/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:21:13 by narso             #+#    #+#             */
/*   Updated: 2022/09/22 19:22:14 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	t_list		*commands;
	t_list		*cur_command;
	t_command	*command;
	char		**env_paths;

	ft_check_args(argc);
	env_paths = ft_get_env_paths(envp);
	if (!env_paths)
		return (EXIT_FAILURE);
	commands = ft_get_commands(argv + 1, argc - 1, env_paths);
	if (!commands)
	{
		ft_free_env_paths(env_paths);
		return (EXIT_FAILURE);
	}
	cur_command = commands;
	while (cur_command)
	{
		command = (t_command *) cur_command->content;
		ft_execute_command(cur_command, envp);
		cur_command = cur_command->next;
	}
	ft_lstclear(&commands, ft_free_command);
	ft_free_env_paths(env_paths);
	return (EXIT_SUCCESS);
}
