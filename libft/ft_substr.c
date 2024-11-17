/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:29:31 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/07 18:15:27 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*to_return;
	size_t	s_size;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	if (start >= s_size)
		return (ft_strdup(""));
	if (len > s_size - start)
		len = s_size - start;
	to_return = (char *)malloc(sizeof(char) * (len + 1));
	if (!to_return)
		return (NULL);
	ft_memcpy(to_return, s + start, len);
	to_return[len] = '\0';
	return (to_return);
}
