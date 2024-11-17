/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@sudent.42perpignan.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:26:04 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/09 17:00:54 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*to_return;
	size_t	size;

	size = ft_strlen(s);
	to_return = ft_calloc(size + 1, sizeof(char));
	if (!to_return)
		return (NULL);
	ft_memcpy(to_return, s, size);
	return (to_return);
}
