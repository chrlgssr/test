/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:28:50 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/08 11:19:04 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	to_return = (char *)ft_calloc(s1_len + s2_len + 1, 1);
	if (!to_return)
		return (NULL);
	ft_memcpy(to_return, s1, s1_len);
	ft_strlcat(to_return, s2, s1_len + s2_len +1);
	return (to_return);
}
