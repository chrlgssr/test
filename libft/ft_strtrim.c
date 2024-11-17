/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:25:23 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/10 16:25:22 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	i = 0;
	while (is_in_set(set, s1[i]) && s1[i] != '\0')
		i++;
	if (i == size)
		return (ft_strdup(""));
	j = size - 1;
	while (is_in_set(set, s1[j]) && j > i)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
