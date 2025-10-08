/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:30:25 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 18:09:05 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*_s1 < *_s2)
			return (*_s1 - *_s2);
		else if (*_s2 < *_s1)
			return (*_s1 - *_s2);
		_s1++;
		_s2++;
		i++;
	}
	return (0);
}
