/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:30:38 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 18:16:12 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*_dest;
	unsigned char	*_src;
	size_t			i;

	_dest = (unsigned char *)dest;
	_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*_dest++ = *_src++;
		i++;
	}
	return (dest);
}
