/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgraser@student.42perpignan.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:51:56 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 14:59:07 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_hexadecimal(unsigned int hex, t_flags *flags, size_t *len, char f)
{
	char	*str_hex;
	int		size;
	
	if (f == 'X')
		str_hex = ft_uitoa_base(hex, "0123456789ABCDEF");
	else
		str_hex = ft_uitoa_base(hex, "0123456789abcdef");
	size = ft_strlen(str_hex);
	if (!flags->left)
	{
		handle_flag_space(flags->space, size, len);
		handle_flag_zero(flags->zero, size, len);
	}
	ft_putstr_fd(str_hex, 1);
	*len += size;
	if (flags->left)
		handle_flag_space(flags->space, size, len);
	free(str_hex);
}
