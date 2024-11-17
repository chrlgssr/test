/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:03:45 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 14:15:59 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_char(int value, t_flags *flags,size_t *len)
{
	if (!flags->left)
	{
		handle_flag_space(flags->space, 1, len);
		handle_flag_space(flags->zero, 1, len);
	}
	ft_putchar_fd((char)value, 1);
	(*len)++;
	if (flags->left)
		handle_flag_space(flags->space, 1, len);
}
