/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:32:30 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 18:49:05 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*_src;
	unsigned char		*_dest;

	if (!dest || !src)
		return (NULL);
	if (src < dest && (const unsigned char *)src + n > (unsigned char *)dest)
	{
		_src = (const unsigned char *)src + n - 1;
		_dest = (unsigned char *)dest + n - 1;
		while (n--)
			*_dest-- = *_src--;
	}
	else
	{
		_src = (const unsigned char *)src;
		_dest = (unsigned char *)dest;
		while (n--)
			*_dest++ = *_src++;
	}
	return (dest);
}
