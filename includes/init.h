/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:30:24 by omaly             #+#    #+#             */
/*   Updated: 2025/10/17 16:22:01 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "pipex.h"

typedef struct s_px	t_px;
void				init_px(t_px *px, int argc, char **argv, char **envp);
int					init_pipes(t_px *px);
int					init_files(t_px *px, int argc, char **argv);
int					init_cmds(t_px *px, char **argv, char **envp);
#endif
