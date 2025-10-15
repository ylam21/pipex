/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:04:21 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 19:58:44 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 5) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*join_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*path;

	if (!dir || !cmd)
		return (NULL);
	tmp = ft_strjoin(dir, "/");
	if (tmp == NULL)
		return (NULL);
	path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (path);
}

char	*find_pathname(const char *cmd, char **envp)
{
	char	**paths;
	char	*pathname;
	int		i;

	i = 0;
	paths = get_paths(envp);
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		pathname = join_path(paths[i], cmd);
		if (pathname == NULL)
			break ;
		if (access(pathname, F_OK) == 0)
		{
			free_split(paths);
			return (pathname);
		}
		free(pathname);
		i++;
	}
	free_split(paths);
	return (NULL);
}
