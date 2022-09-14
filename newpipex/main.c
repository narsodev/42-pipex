/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:21:13 by narso             #+#    #+#             */
/*   Updated: 2022/08/30 14:45:00 by narso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	main(int argc, char **argv, char **envp)
{
	t_list	*commands;

	ft_check_args(argc);
	commands = ft_get_commands(argv);
	if (!commands)
	{
		return (EXIT_FAILURE);
	}	
	return (EXIT_SUCCESS);
}
