/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:17:50 by narso             #+#    #+#             */
/*   Updated: 2022/08/30 14:44:46 by narso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ft_get_commands(char **argv)
{
	t_list	*commands;

	return (commands);
}

t_list	*create_command(char *path, int type)
{
	t_list *command;
	t_command *content;

	content = ft_calloc(1, sizeof(t_lsit));
	if (!content)
		return (NULL);
	content->path = path;
	content-type = type;
	command = ft_lstnew((void *) content);
	if (!command)
	{
		free(content);
	}

	return (command);
}
