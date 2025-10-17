/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:49:42 by omaly             #+#    #+#             */
/*   Updated: 2025/10/17 18:08:23 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipes(int **pipes, int pipe_count)
{
	int	i;

	if (pipes == NULL)
		return ;
	i = 0;
	while (i < pipe_count)
	{
		free(pipes[i]);
		pipes[i] = NULL;
		i++;
	}
	free(pipes);
	pipes = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	free_cmds(t_px *px)
{
	int	i;

	if (px->cmds == NULL)
		return ;
	i = 0;
	while (i < px->cmd_count)
	{
		free(px->cmds[i].pathname);
		px->cmds[i].pathname = NULL;
		free_split(px->cmds[i].argv);
		px->cmds[i].argv = NULL;
		i++;
	}
	free(px->cmds);
	px->cmds = NULL;
}

void	free_px(t_px *px)
{
	free_pipes(px->pipes, px->cmd_count - 1);
	free_cmds(px);
}
