/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:21:13 by narso             #+#    #+#             */
/*   Updated: 2022/09/26 20:01:45 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_execute_commands(t_list *commands, char **envp)
{
	t_list		*cur_command;
	t_command	*command;

	cur_command = commands;
	while (cur_command)
	{
		command = (t_command *) cur_command->content;
		ft_execute_command(cur_command, envp);
		cur_command = cur_command->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_list		*commands;
	char		**env_paths;
	char		*limiter;

	limiter = ft_check_args(argc, argv);
	env_paths = ft_get_env_paths(envp);
	if (!env_paths)
		return (EXIT_FAILURE);
	if (limiter)
		commands = ft_get_commands(argv + 2, argc - 2, env_paths, limiter);
	else
		commands = ft_get_commands(argv + 1, argc - 1, env_paths, NULL);
	ft_execute_commands(commands, envp);
	ft_free_env_paths(env_paths);
	ft_lstclear(&commands, ft_free_command);
	return (EXIT_SUCCESS);
}
