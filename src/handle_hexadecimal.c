/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgraser@student.42perpignan.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:51:56 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/20 20:20:28 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*handle_flag_hash(unsigned int hex, t_flags *flags, char f)
{
	char	*base;

	if (f ==  'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (flags->hash)
		return (ft_ptrtoa_base((unsigned long int)hex, base));
	return (ft_uitoa_base(hex, base));
}

void	handle_hexadecimal(unsigned int hex, t_flags *flags, size_t *len, char f)
{
	char	*str_nbr;
	int		size_s;

	str_nbr = handle_flag_hash(hex, flags, f);
	size_s = ft_strlen(str_nbr);
	if (flags->precision > size_s)
		return (handle_integer_precision(0, str_nbr, flags, len));
	if (!flags->minus)
		handle_integer_no_minus(0, flags, len, size_s);
	else if(flags->plus || flags->space)
		handle_flag_print(0, flags, len);
	ft_putstr_fd(str_nbr, 1);
	if (flags->minus)
	{
		if (flags->plus || flags->space)
			handle_flag_width(flags->width, size_s + 1, len, SPACE);
		else
			handle_flag_width(flags->width, size_s, len, SPACE);
	}
	free(str_nbr);
	*len += size_s;

}
