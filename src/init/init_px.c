/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:47:14 by omaly             #+#    #+#             */
/*   Updated: 2025/10/16 20:01:27 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	init_px(t_px *px, int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (1);
	px->here_doc = ft_strncmp(argv[1], "here_doc", 9) == 0;
	px->cmd_count = argc - 3 - px->here_doc;
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
