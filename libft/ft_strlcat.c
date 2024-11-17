/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:05:44 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/06 17:19:42 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	i = 0;
	if (size > dst_size)
	{
		while (src[i] && (dst_size + i) < size - 1)
		{
			dst[dst_size + i] = src[i];
			i++;
		}
		dst[dst_size + i] = '\0';
	}
	if (dst_size >= size)
		dst_size = size;
	return (dst_size + ft_strlen(src));
}
