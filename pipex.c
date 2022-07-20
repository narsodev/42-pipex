#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"

char	**get_paths(char **envp)
{
	int		i;
	char	**temp_paths;
	char	**paths;

	while (envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	if (!envp[i])
		return (NULL);
	temp_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (temp_paths[i])
		i++;
	paths = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (temp_paths[i])
	{
		paths[i] = ft_strjoin(temp_paths[i], "/");
		i++;
	}
	return (paths);
}

char	*find_command(char *command, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	if (*command == '/')
		return (command);
	paths = get_paths(envp);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], command);
		if (!path)
			return (NULL);
		if (!access(path, X_OK))
			return (path);
		errno = 0;
		free(path);
		i++;
	}
	if ((!ft_strncmp(command, "./", 2) || ft_strchr(command, '/') && !access(command, X_OK)))
		return (command);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(": command not found", 2);
	errno = 127;
	return (NULL);
}

char	**ft_parse_args(char *command)
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
	clean_command = ft_strtrim(command, " ");
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

char	**ft_argv(char *command, char **envp)
{
	char	**strings;
	char	**argv;
	size_t	i;

	strings = ft_parse_args(command);
	if (!strings)
		return (NULL);
	i = 0;
	while (strings[i])
		i++;
	argv = ft_calloc(i + 1, sizeof(char *));
	if (!argv)
	{
		free(strings);
		return (NULL);
	}
	argv[0] = find_command(strings[0], envp);
	if (!argv[0])
	{
		free(argv);
		return (NULL);
	}
	i = 1;
	while (strings[i])
	{
		argv[i] = strings[i];
		i++;
	}
	free(strings);
	return (argv);
}

int	ft_exec(char *command, int fd_input, int fd_output, char **envp, pid_t *pid)
{
	char *const	*argv;
	argv = ft_argv(command, envp);
	int		ptcfd[2];
	int		ctpfd[2];

	pid_t	 w_pid;
	int	wstatus;

	int	pipestatus;

	pipestatus = pipe(ctpfd);
	if (pipestatus == -1)
	{
		perror("pipe");
		return (-1);
	}
	pipestatus = pipe(ptcfd);
	if (pipestatus == -1)
	{
		perror("pipe");
		return (-1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (*pid == 0)
	{
		close(ptcfd[1]);
		close(ctpfd[0]);
		if (fd_input > 0)
			dup2(fd_input, 0);
		else
			dup2(ptcfd[0], 0);
		if (fd_output > 0)
			dup2(fd_output, 1);
		else
			dup2(ctpfd[1], 1);
		execve(argv[0], argv, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(ptcfd[1]);
		close(ptcfd[0]);
		close(ctpfd[1]);
		//w_pid = waitpid(pid, &wstatus, 0);
		return (ctpfd[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_exec;
	int	fd_input;
	int	fd_output;
	int stdoutCopy;
	int	wstatus;
	int	exit_code;
	pid_t	pid_1, pid_2;
	
	if (argc != 5)
		return (EXIT_FAILURE);
	fd_output = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_output == -1)
	{
		perror("open");
		close(fd_input);
		return (EXIT_FAILURE);
	}
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
		perror("pipex: input");
	int	fd_exec2 = ft_exec(argv[2], fd_input, -1, envp, &pid_1);
	fd_exec = ft_exec(argv[3], fd_exec2, fd_output, envp, &pid_2);
	close(fd_exec2);
	close(fd_exec);
	if (fd_input > 0)
		close(fd_input);
	//if (WEXITSTATUS(wstatus) != EXIT_SUCCESS)
	//	exit_code = WEXITSTATUS(wstatus);
	exit_code = errno;
	
	//wait both childs??
	close(fd_output);
	return (exit_code);
}
