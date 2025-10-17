/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:47:14 by omaly             #+#    #+#             */
/*   Updated: 2025/10/17 17:47:08 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	init_px(t_px *px, int argc, char **argv, char **envp)
{
	if (argc < 5)
		exit(EXIT_FAILURE);
	px->here_doc = ft_strncmp(argv[1], "here_doc", 9) == 0;
	px->cmd_count = argc - 3 - px->here_doc;
	if (init_files(px, argc, argv) != 0)
		exit(EXIT_FAILURE);
	if (init_pipes(px) != 0)
		exit(EXIT_FAILURE);
	if (init_cmds(px, argv, envp) != 0)
		exit(EXIT_FAILURE);
}
