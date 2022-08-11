/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:32:48 by ngonzale          #+#    #+#             */
/*   Updated: 2022/08/11 20:09:18 by ngonzale         ###   ########.fr       */
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
	//if (!fd_read)
	//	ft_open_file();
	i = 0;
}

void	ft_exec_commands(t_list *commands)
{
	t_command	*command;

	while (commands)
	{
		command = (t_command *) commands->content;
		if (command->type == FILE_READ)
			((t_command *)commands->next->content)->fd_read = open(command->args[0], O_RDONLY);
		ft_printf("fd: %d\n", command->fd_read);
		commands = commands->next;
	}
}

int	main(int argc, char **argv)
{
	t_list *commands;

	if (argc != 5)
	{
		ft_printf("five args required!\n");
		return (1);
	}

	commands = ft_parse_args(argc, argv);
	ft_exec_commands(commands);

}
