/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:24:31 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 19:54:24 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	alloc_pipes(t_px *px, int pipe_count)
{
	int	i;

	px->pipe_fds = malloc(sizeof(int *) * pipe_count);
	if (px->pipe_fds == NULL)
	{
		perror("malloc");
		return (1);
	}
	i = 0;
	while (i < pipe_count)
	{
		px->pipe_fds[i] = malloc(sizeof(int) * 2);
		if (px->pipe_fds[i] == NULL)
		{
			perror("malloc");
			free_pipes(px);
			return (2);
		}
		i++;
	}
	return (0);
}

int	init_pipes(t_px *px)
{
	int	i;
	int	pipe_count;

	i = 0;
	pipe_count = px->cmd_count - 1;
	if (alloc_pipes(px, pipe_count) != 0)
		return (1);
	while (i < pipe_count)
	{
		if (pipe(px->pipe_fds[i]) == -1)
		{
			perror("pipe");
			free_pipes(px);
			return (2);
		}
		i++;
	}
	return (0);
}
