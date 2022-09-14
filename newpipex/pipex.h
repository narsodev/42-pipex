/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:27 by narso             #+#    #+#             */
/*   Updated: 2022/08/30 14:44:57 by narso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"

typedef struct	s_command {
	char	*path;
	int	type;
}		t_command;

// Checker
void	ft_check_args(int argc);

// Args
t_list *ft_get_commands(char **argv);

#endif
