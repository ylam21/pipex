/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:20:35 by omaly             #+#    #+#             */
/*   Updated: 2025/10/16 00:00:08 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// LIBRARIES
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
// LIBFT
# include "../libft/libft.h"
// PROJECTS MODULES
# include "free.h"
# include "init.h"
# include "usage.h"

typedef struct s_cmd
{
	char	**argv;
	char	*pathname;
	int		in_fd;
	int		out_fd;
}			t_cmd;

typedef struct s_px
{
	int		infile;
	int		outfile;
	int		cmd_count;
	t_cmd	*cmds;
	int		**pipe_fds;
	int		here_doc;
}			t_px;

void		close_fds(t_px *px);
char		*find_pathname(const char *cmd, char **envp);
int			heredoc_pipe(char *limiter);
#endif
