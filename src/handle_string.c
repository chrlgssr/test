/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:49:59 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 11:17:30 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_precision(char *s, int size, int precision)
{
	char	*new_str;

	if (size >= precision)
		return (s);
	new_str = ft_substr(s, 0, precision);
	if (!new_str)
		return (NULL);
	return (new_str);
}
static void	ft_null(size_t *len)
{
	ft_putstr_fd("(null)", 1);
	*len += 6;
}

void	handle_string(char *s, t_flags *flags, size_t *len)
{
	size_t	size;

	if (!s)
		return (ft_null(len));
	size = ft_strlen(s);
	if (!flags->left)
		handle_flag_space(flags->space, size, len);
	ft_putstr_fd(s, 1);
	*len += size;
	if (flags->left)
		handle_flag_space(flags->space, size, len);
}
