/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:20:06 by omaly             #+#    #+#             */
/*   Updated: 2025/10/17 16:52:59 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	init_files(t_px *px, int argc, char **argv)
{
	if (px->here_doc == 0)
		px->infile = open(argv[1], O_RDONLY);
	if (px->here_doc)
		px->infile = heredoc_pipe(argv[2]);
	if (px->infile == -1)
		perror("open");
	if (px->here_doc)
		px->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		px->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile == -1)
		perror("open");
	return (0);
}
