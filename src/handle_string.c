/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:49:59 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/20 13:10:20 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_string(char *s, t_flags *flags, size_t *len)
{
	int	size_s;
	
	if (!s)
		size_s = 6;
	else
		size_s = ft_strlen(s);
	if (flags->precision >= 0 && flags->precision < size_s)
		size_s = flags->precision;
	if (!flags->minus)
		handle_flag_width(flags->width, size_s, len, SPACE);
	if (!s)
		write(1, "(null)", size_s);
	else
		write(1, s, size_s);
	if (flags->minus)
		handle_flag_width(flags->width, size_s, len, SPACE);
	*len += size_s;
}
