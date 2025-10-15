/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:39:25 by omaly             #+#    #+#             */
/*   Updated: 2025/10/15 21:44:53 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USAGE_H
# define USAGE_H

typedef enum e_usage_type
{
	STANDARD,
	BONUS
}		t_usage_type;

void	usage(t_usage_type type);
#endif
