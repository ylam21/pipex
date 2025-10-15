/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 23:55:27 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 23:55:42 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_heredoc_line(void)
{
	char	*line;
	int		i;
	char	c;

	line = malloc(4096);
	if (line == NULL)
		return (perror("malloc"), NULL);
	i = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
			break ;
		line[i] = c;
		i++;
	}
	if (i == 0 && c != '\n')
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

int	heredoc_pipe(char *limiter)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		return (perror("pipe"), -1);
	while (1)
	{
		line = get_heredoc_line();
		if (line == NULL || ft_strncmp(line, limiter, ft_strlen(limiter)
				+ 1) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	return (fd[0]);
}
