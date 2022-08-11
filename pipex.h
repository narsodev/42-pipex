/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:28:16 by ngonzale          #+#    #+#             */
/*   Updated: 2022/08/11 19:57:49 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# define FILE_READ 0
# define FILE_WRITE 1
# define COMMAND 2

typedef struct s_command {
	char	**args;
	int 	type;
	int		fd_read;
}				t_command;

t_list	*ft_parse_args(int argc, char **argv);

void	ft_free_command(void *content);

#endif
