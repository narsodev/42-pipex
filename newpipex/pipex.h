/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:27 by narso             #+#    #+#             */
/*   Updated: 2022/09/19 20:26:36 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# define TYPE_FILE_READ 0
# define TYPE_FILE_WRITE 1
# define TYPE_COMMAND 2

typedef struct	s_command {
	char	*path;
	char	**args;
	int		type;
	int		fd_input;
	int		fd_output;
	int		fd_opened;
}		t_command;

// Checker
void	ft_check_args(int argc);

// Args
t_list *ft_get_commands(char **argv, int argc, char *env_path);

// Commands
void	ft_execute_command(t_list *lstcommand, char **envp);
t_list	*ft_create_command(char *argv, int type, char *env_path);
void	ft_free_command(void *content);

// Parser
char	**ft_parse_command(char *arg);

// Exec
int	ft_exec(t_command *command, char **envp);

// Path
char	*ft_get_env_path(char **envp);
char	*ft_find_path(char *command, char *env_path);

#endif
