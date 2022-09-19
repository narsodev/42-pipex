/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:47:33 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/16 18:26:50 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_path_is_ok(char *command, char *env_path)
{
	char	*path;
	char	*aux;

	aux = ft_strjoin(env_path, "/");
	if (!aux)
		return (NULL);
	path = ft_strjoin(aux, command);
	free(aux);
	if (!path)
		return (NULL);
	if (!access(path, X_OK))
		return (path);
	free(path);
	return (NULL);
}

char	*ft_find_path(char *command, char *env_path)
{
	char	**paths;
	char	**ptr;
	char	*path;
	
	if (command[0] == '/' || !ft_strncmp(command, "./", 2) || !ft_strncmp(command, "../", 3))
		return (ft_strdup(command));
	paths = ft_split(env_path, ':');
	if (!paths)
		return (NULL);
	ptr = paths;
	path = NULL;
	while (*ptr)
	{
		if (!path)
			path = ft_path_is_ok(command, *ptr);
		free(*ptr);
		ptr++;
	}
	free(paths);
	return (path);
}

char	*ft_get_env_path(char **envp)
{
	char	**ptr;

	ptr = envp;
	while (*ptr)
	{
		if (!ft_strncmp(*ptr, "PATH=", 5))
			return (*ptr + 5);
		ptr++;
	}
	return (NULL);
}
