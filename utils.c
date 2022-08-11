/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:24:04 by ngonzale          #+#    #+#             */
/*   Updated: 2022/08/11 18:35:42 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdlib.h>

void	ft_free_command(void *content)
{
	t_command *command;
	size_t	i;

	command = (t_command *) content;
	i = 0;
	while (command->args[i])
	{
		free(command->args[i]);
		i++;
	}
	free(command->args);
	free(command);
}
