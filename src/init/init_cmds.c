/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:26:19 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 19:31:44 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	set_cmd_fds(t_px *px, int i)
{
	if (i == 0)
	{
		px->cmds[i].in_fd = px->infile;
		px->cmds[i].out_fd = px->pipe_fds[i][1];
	}
	else if (i == px->cmd_count - 1)
	{
		px->cmds[i].in_fd = px->pipe_fds[i - 1][0];
		px->cmds[i].out_fd = px->outfile;
	}
	else
	{
		px->cmds[i].in_fd = px->pipe_fds[i - 1][0];
		px->cmds[i].out_fd = px->pipe_fds[i][1];
	}
}

int	init_single_cmd(t_px *px, char **argv, char **envp, int i)
{
	char	**cmd_argv;

	cmd_argv = ft_split(argv[i + 2], ' ');
	if (cmd_argv == NULL)
	{
		perror("ft_split");
		return (2);
	}
	px->cmds[i].argv = cmd_argv;
	px->cmds[i].pathname = find_pathname(cmd_argv[0], envp);
	if (px->cmds[i].pathname == NULL)
	{
		free_split(cmd_argv);
		return (3);
	}
	set_cmd_fds(px, i);
	return (0);
}

int	init_cmds(t_px *px, char **argv, char **envp)
{
	int	i;

	px->cmds = malloc(sizeof(t_cmd) * px->cmd_count);
	if (px->cmds == NULL)
	{
		perror("malloc");
		return (1);
	}
	i = 0;
	while (i < px->cmd_count)
	{
		if (init_single_cmd(px, argv, envp, i) != 0)
			return (2);
		i++;
	}
	return (0);
}
