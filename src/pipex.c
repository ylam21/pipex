/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:21:37 by omaly             #+#    #+#             */
/*   Updated: 2025/10/08 18:37:09by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid;

	(void)envp;
	(void)argv;
	if (argc != 5)
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	if (pipe(fds) == -1)
	{
		printf("Error with opening pipe\n");
		return (2);
	}
	pid = fork();
	if (pid == -1)
	{
		printf("Error with fork\n");
		close(fds[0]);
		close(fds[1]);
		return (3);
	}
	else if (pid == 0)
	{
		// child_process(fds);
	}
	wait(NULL);
	// parent_process();
	return (0);
}
