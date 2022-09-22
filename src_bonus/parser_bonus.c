/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:47:26 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/20 20:52:01 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_count_args(char *command, size_t *argc)
{
	char	*ptr;
	char	searching;

	*argc = 1;
	ptr = command;
	searching = 0;
	while (*ptr)
	{
		if (*ptr == searching)
			searching = 0;
		if (!searching && ft_strchr("\"'", *ptr))
		{
			searching = *ptr;
			if (*argc == 1)
				*ptr = '\\';
		}
		if (!searching && *ptr == ' ')
		{
			*ptr = 0;
			if (*(ptr + 1) != ' ')
				*argc += 1;
		}
		ptr++;
	}
}

void	ft_manipulate_arg(char **string)
{
	char	**aux;
	char	*s;
	size_t	j;

	if (*string[0] == '\'' || *string[0] == '\"')
	{
		s = ft_calloc(2, sizeof(char));
		s[0] = *string[0];
		*string = ft_strtrim(*string, s);
	}
	aux = ft_split(*string, '\\');
	*string = ft_strdup("");
	j = 0;
	while (aux[j])
	{
		*string = ft_strjoin(*string, aux[j]);
		j++;
	}
}

void	ft_separate_command(char **strings, char *ptr,
		size_t argc, size_t i)
{
	while (++i < argc)
	{
		while (!*ptr)
			ptr++;
		strings[i] = ft_strdup(ptr);
		ft_manipulate_arg(strings + i);
		while (*ptr)
			ptr++;
	}
}

char	**ft_parse_command(char *arg)
{
	char	*ptr;
	size_t	argc;
	char	**strings;
	char	*clean_command;

	clean_command = ft_strtrim(arg, " ");
	if (!clean_command)
		return (NULL);
	ft_count_args(clean_command, &argc);
	strings = ft_calloc(argc + 1, sizeof(char *));
	if (!strings)
	{
		free(clean_command);
		return (NULL);
	}
	ptr = clean_command;
	ft_separate_command(strings, ptr, argc, -1);
	free(clean_command);
	return (strings);
}
