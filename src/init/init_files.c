/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:20:06 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 20:36:00 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	init_files(t_px *px, int argc, char **argv)
{
	px->infile = open(argv[1], O_RDONLY);
	if (px->infile == -1)
	{
		perror("open infile");
		return (1);
	}
	px->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile == -1)
	{
		perror("open outfile");
		return (2);
	}
	return (0);
}

