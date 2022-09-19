/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:47:26 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/14 20:48:38 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char **ft_parse_command(char *arg)
{
	char	*ptr;
	size_t	argc;
	size_t	i;
	size_t	j;
	int	searching_quote;
	int	searching_dquote;
	int	before;
	char	*clean_command;
	char	**strings;
	char	**aux;

	argc = 1;
	before = 0;
	searching_quote = 0;
	searching_dquote = 0;
	clean_command = ft_strtrim(arg, " ");
	ptr = clean_command;
	while (*ptr)
	{
		if (*ptr == '\'' && (ptr == clean_command || (*(ptr -1) != '\\' || before)))
		{
			if (searching_quote)
				searching_quote = 0;
			else
				searching_quote = 1;
			if (argc == 1)
				*ptr = '\\';
			before = 1;
		}
		else
			before = 0;
		if (*ptr == '\"' && (ptr == clean_command || (*(ptr -1) != '\\' || before )))
		{
			if (searching_dquote)
				searching_dquote = 0;
			else
				searching_dquote = 1;
			if (argc == 1)
				*ptr = '\\';
			before = 1;
		}
		else
			before = 0;
		/*
		if ((*ptr == '\"' || *ptr == '\'') && (ptr == clean_command || *(ptr - 1) != '\\') && (!searching || searching == *ptr))
		{
			if (searching)
				searching = 0;
			else
				searching = *ptr;
		}
		*/
		if (!searching_dquote && !searching_quote && *ptr == ' ')
		{
			*ptr = 0;
			if (*(ptr + 1) != ' ')
				argc++;
		}
		ptr++;
	}
	ptr = clean_command;
	i = 0;
	i = 0;
	while (i < argc)
	{
		while (*ptr)
		{
			ptr++;
		}
//		printf(" - ");
		i++;
		ptr++;
	}
	//printf("argc: %zu\n", argc);
	strings = ft_calloc(argc + 1, sizeof(char *));
	i = 0;
	ptr = clean_command;
	while (i < argc)
	{
		while (!*ptr)
			ptr++;
		strings[i] = ft_strdup(ptr);
		if (strings[i][0] == '\'' || strings[i][0] == '\"')
		{
			char	*s;
			s = ft_calloc(2, sizeof(char));
			s[0] = strings[i][0];
			strings[i] = ft_strtrim(strings[i], s);
		}
		aux = ft_split(strings[i], '\\');
		strings[i] = ft_strdup("");	
		j = 0;
		while (aux[j])
		{
			strings[i] = ft_strjoin(strings[i], aux[j]);
			j++;
		}
		while (*ptr)
			ptr++;
		ptr++;
		i++;
	}

	free(clean_command);

	return (strings);
}

