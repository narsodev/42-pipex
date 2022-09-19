/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:17:50 by narso             #+#    #+#             */
/*   Updated: 2022/09/19 20:27:01 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void	ft_open_file_to_read(t_list *lstcommand)
{
	t_command	*command;
	t_command	*next_command;
	int			fd;

	command = (t_command *)lstcommand->content;
	next_command = (t_command *)lstcommand->next->content;
	fd = open(command->path, O_RDONLY);
	if (fd > 0)
	{
		next_command->fd_input = fd;
		command->fd_opened = fd;
	}
	else
	{
		perror("pipex");
	}
}

void	ft_open_file_to_write(t_command *prevcommand, t_command *file)
{
	int			fd;

	fd = open(file->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd > 0)
	{
		prevcommand->fd_output = fd;
		file->fd_opened = fd;
	}
	else
	{
		perror("open");
	}
}

void	ft_execute_command(t_list *lstcommand, char **envp)
{
	t_command	*command;
	t_command	*next_command;

	command = (t_command *)lstcommand->content;
	next_command = NULL;
	if (lstcommand->next)
		next_command = (t_command *)lstcommand->next->content;
	if (command->type == TYPE_FILE_READ)
		ft_open_file_to_read(lstcommand);
	if (command->type == TYPE_COMMAND)
	{
		if (next_command && next_command->type == TYPE_FILE_WRITE)
		{
			ft_open_file_to_write(command, next_command);
			ft_exec(command, envp);
		}
		else if (next_command && next_command->type == TYPE_COMMAND)
		{
			command->fd_output = -1;
			next_command->fd_input = ft_exec(command, envp);
		}
	}
}

t_list	*ft_get_commands(char **argv, int argc, char *env_path)
{
	t_list	*commands;
	t_list	*aux;
	int		i;

	commands = ft_create_command(argv[0], TYPE_FILE_READ, NULL);
	if (!commands)
		return (NULL);
	i = 1;
	while (i < argc - 1)
	{
		aux = ft_create_command(argv[i], TYPE_COMMAND, env_path);
		if (!aux)
		{
			ft_lstclear(&commands, ft_free_command);
			return (NULL);
		}
		ft_lstadd_back(&commands, aux);
		i++;
	}
	aux = ft_create_command(argv[argc - 1], TYPE_FILE_WRITE, NULL);
	if (!aux)
	{
		ft_lstclear(&commands, ft_free_command);
		return (NULL);
	}
	ft_lstadd_back(&commands, aux);
	return (commands);
}

t_list	*ft_create_command(char *argv, int type, char *env_path)
{
	t_list		*command;
	t_command	*content;

	command = NULL;
	content = ft_calloc(1, sizeof(t_command));
	if (content)
		command = ft_lstnew((void *) content);
	if (!command)
		return (NULL);
	content->type = type;
	content->fd_input = STDIN_FILENO;
	content->fd_output = STDOUT_FILENO;
	if (type == TYPE_COMMAND)
	{
		content->args = ft_parse_command(argv);
		if (!content->args)
		{
			free(content);
			free(command);
			return (NULL);
		}
		content->path = ft_find_path(content->args[0], env_path);
	}
	else
		content->path = argv;
	return (command);
}

void	ft_free_command(void *content)
{
	t_command	*command;
	char		**args;

	command = (t_command *) content;
	if (command->type == TYPE_COMMAND)
	{
		if (command->path)
			free(command->path);
		args = command->args;
		if (args)
		{
			while (*args)
			{
				free(*args);
				args++;
			}
			free(command->args);
		}
	}
	free(command);
}
