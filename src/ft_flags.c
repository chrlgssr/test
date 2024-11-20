/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:39:44 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/19 15:09:51 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags	*ft_flagsnew(void)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	ft_reset_flags(flags);
	return (flags);
}
void	ft_reset_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->precision = -1;
	flags->width = 0;
}

void	handle_flag_width(int width, int len_word, size_t *len, int c)
{
	int		nb_space;
	char	to_print;

	if (c == SPACE)
		to_print = ' ';
	else
		to_print = '0';
	nb_space = width - len_word;
	while (nb_space-- > 0)
	{
		ft_putchar_fd(to_print, 1);
		(*len)++;
	}
}
