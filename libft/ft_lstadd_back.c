/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:27:33 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 14:26:07 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last;

	if (!lst || !newlst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = newlst;
}
