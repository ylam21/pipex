/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:24:31 by omaly             #+#    #+#             */
/*   Updated: 2025/10/17 18:08:14 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	alloc_pipes(t_px *px, int pipe_count)
{
	int	i;

	px->pipes = malloc(sizeof(int *) * pipe_count);
	if (px->pipes == NULL)
	{
		perror("malloc");
		return (1);
	}
	i = 0;
	while (i < pipe_count)
	{
		px->pipes[i] = malloc(sizeof(int) * 2);
		if (px->pipes[i] == NULL)
		{
			perror("malloc");
			free_pipes(px->pipes, px->cmd_count - 1);
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
		if (pipe(px->pipes[i]) == -1)
		{
			perror("pipe");
			free_pipes(px->pipes, px->cmd_count - 1);
			return (2);
		}
		i++;
	}
	return (0);
}
