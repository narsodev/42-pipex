/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:27 by narso             #+#    #+#             */
/*   Updated: 2022/09/22 20:18:21 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"

# define TYPE_FILE_READ 0
# define TYPE_FILE_WRITE 1
# define TYPE_COMMAND 2

typedef struct s_command {
	char	*path;
	char	**args;
	int		type;
	int		fd_input;
	int		fd_output;
}		t_command;

// Checker
void	ft_check_args(int argc);

// Commands
t_list	*ft_get_commands(char **argv, int argc, char **env_paths);
void	ft_execute_command(t_list *lstcommand, char **envp);
t_list	*ft_create_command(char *argv, int type, char **env_paths);
void	ft_free_command(void *content);
void	ft_free_env_paths(char **env_paths);

// Parser
char	**ft_parse_command(char *arg);

// Exec
int		ft_exec(t_command *command, char **envp);

// Path
char	**ft_get_env_paths(char **envp);
char	*ft_find_path(char *command, char **env_paths);

#endif
