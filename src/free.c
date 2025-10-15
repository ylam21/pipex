/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:49:42 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 19:47:52 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipes(t_px *px)
{
	int	pipe_count;
	int	i;

	pipe_count = px->cmd_count - 1;
	i = 0;
	while (i < pipe_count)
	{
		free(px->pipe_fds[i]);
		i++;
	}
	free(px->pipe_fds);
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_cmds(t_px *px)
{
	int	i;

	i = 0;
	while (i < px->cmd_count)
	{
		free(px->cmds[i].pathname);
		free_split(px->cmds[i].argv);
		i++;
	}
	free(px->cmds);
}

void	free_px(t_px *px)
{
	free_pipes(px);
	free_cmds(px);
}
