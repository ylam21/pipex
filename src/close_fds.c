/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:50 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 23:43:45 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(t_px *px)
{
	int	i;
	int	pipe_count;

	close(px->infile);
	close(px->outfile);
	i = 0;
	pipe_count = px->cmd_count - 1;
	while (i < pipe_count)
	{
		close(px->pipe_fds[i][0]);
		close(px->pipe_fds[i][1]);
		i++;
	}
}
