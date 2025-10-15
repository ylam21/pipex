/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:47:14 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 19:30:12 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	init_px(t_px *px, int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile\n", 2);
		return (1);
	}
	px->cmd_count = argc - 3;
	if (init_files(px, argc, argv) != 0)
		return (2);
	if (init_pipes(px) != 0)
		return (3);
	if (init_cmds(px, argv, envp) != 0)
	{
		free_pipes(px);
		return (4);
	}
	return (0);
}
