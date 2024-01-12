/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:40:42 by dghazary          #+#    #+#             */
/*   Updated: 2022/10/12 21:41:10 by dghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_helper(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*str;
	int		i;

	i = 0;
	paths = path_helper(envp);
	while (paths[i])
	{
		str = ft_strjoin(paths[i], "/");
		path = ft_strjoin(str, cmd);
		free(str);
		if (access(path, F_OK | X_OK) == 0)
		{
			split_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	split_free(paths);
	return (0);
}
