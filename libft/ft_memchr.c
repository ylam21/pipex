/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:30:11 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 18:08:36 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*_s;
	size_t			i;

	_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*_s == (unsigned char)c)
			return (_s);
		_s++;
		i++;
	}
	return (NULL);
}
