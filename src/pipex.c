/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:21:37 by omaly             #+#    #+#             */
/*   Updated: 2025/10/17 18:26:31 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_cmd(t_px *px, int idx, char **envp)
{
	t_cmd	cmd;

	cmd = px->cmds[idx];
	if (dup2(cmd.in_fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd.out_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close_fds(px);
	execve(cmd.pathname, cmd.argv, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	wait_children(t_px *px)
{
	int	i;

	i = 0;
	while (i < px->cmd_count)
	{
		wait(NULL);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_px	px;
	pid_t	pid;
	int		i;

	init_px(&px, argc, argv, envp);
	i = 0;
	while (i < px.cmd_count)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			exec_cmd(&px, i, envp);
		i++;
	}
	close_fds(&px);
	free_px(&px);
	wait_children(&px);
	return (0);
}
