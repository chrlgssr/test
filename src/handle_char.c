/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:03:45 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/20 12:54:23 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_char(int value, t_flags *flags,size_t *len)
{
	if (!flags->minus)
		handle_flag_width(flags->width, 1, len, SPACE);
	ft_putchar_fd((char)value, 1);
	if (flags->minus)
		handle_flag_width(flags->width, 1, len, SPACE);
	(*len)++;
}
