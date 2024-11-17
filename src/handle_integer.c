/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:01:48 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 15:36:57 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_integer(int value, t_flags *flags, size_t *len)
{
	char	*str_nbr;
	int		size;

	str_nbr = ft_itoa(value);
	size = ft_strlen(str_nbr);
	if (!flags->left)
	{
		handle_flag_space(flags->space, size, len);
		if (flags->zero && value < 0)
			ft_putchar_fd('-', 1);
		handle_flag_zero(flags->zero, size, len);
		if (flags->precision)
			handle_flag_zero(flags->zero, size, len);
	}
	if (flags->zero && value < 0)
		ft_putstr_fd(str_nbr + 1, 1);
	else
		ft_putstr_fd(str_nbr, 1);
	*len += size;
	if (flags->left)
		handle_flag_space(flags->space, size, len);
	free(str_nbr);
}
