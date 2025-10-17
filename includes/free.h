/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:34:21 by omaly             #+#    #+#             */
/*   Updated: 2025/10/17 18:24:04 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "pipex.h"

typedef struct s_px	t_px;
void				free_px(t_px *px);
void				free_split(char **split);
void				free_pipes(int **pipes, int pipe_count);
#endif
