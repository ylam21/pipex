/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:32:44 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 18:11:06 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*_s;
	size_t			i;

	_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*_s++ = (unsigned char)c;
		i++;
	}
	return (s);
}
