/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:31:05 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/21 18:34:06 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"
#include <unistd.h>

void		ft_free_command(void *content);
t_list		*ft_create_command(char *argv, int type, char *env_path);
static void	ft_create_command_helper(t_list **command, t_command **content);

t_list	*ft_create_command(char *argv, int type, char *env_path)
{
	t_list		*command;
	t_command	*content;

	ft_create_command_helper(&command, &content);
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

static void	ft_create_command_helper(t_list **command, t_command **content)
{
	*content = ft_calloc(1, sizeof(t_command));
	if (!*content)
		return ;
	*command = ft_lstnew((t_list *) *content);
	if (!*command)
		free(*content);
}
