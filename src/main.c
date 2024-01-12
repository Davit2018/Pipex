/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:37:48 by dghazary          #+#    #+#             */
/*   Updated: 2022/10/12 21:37:52 by dghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process1(int *pfd, int *ofd, char **argv, char **envp)
{
	char	**cmd;
	pid_t	pidt;

	pidt = fork();
	if (pidt < 0)
		go_out();
	if (pidt == 0)
	{
		cmd = ft_split(argv[2], ' ');
		ofd[0] = open(argv[1], O_RDONLY);
		if (ofd[0] < 0)
			go_out();
		close(pfd[0]);
		dup2(ofd[0], 0);
		dup2(pfd[1], 1);
		if (cmd[0] && get_path(cmd[0], envp))
		{
			execve(get_path(cmd[0], envp), cmd, envp);
			split_free(cmd);
		}
		else
			go_out();
	}
}

void	process2(int *pfd, int *ofd, char **argv, char **envp)
{
	char	**cmd;
	pid_t	pidt;

	pidt = fork();
	if (pidt < 0)
		go_out();
	if (pidt == 0)
	{
		cmd = ft_split(argv[3], ' ');
		ofd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (ofd[1] < 0)
			go_out();
		close(pfd[1]);
		dup2(ofd[1], 1);
		dup2(pfd[0], 0);
		if (cmd[0] && get_path(cmd[0], envp))
		{
			execve(get_path(cmd[0], envp), cmd, envp);
			split_free(cmd);
		}
		else
			go_out();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	pfd[2];
	int	ofd[2];

	i = 0;
	if (argc != 5)
		go_out();
	if (pipe(pfd) < 0)
		go_out();
	process1(pfd, ofd, argv, envp);
	process2(pfd, ofd, argv, envp);
	close(pfd[0]);
	close(pfd[1]);
	wait(0);
	wait(0);
	return (0);
}
