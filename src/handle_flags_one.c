/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:07:30 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 14:44:54 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_flag_zero(int flag_zero, int len_word, size_t *len)
{
	int	nb_space;

	nb_space = flag_zero - len_word;
	while (nb_space-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*len)++;
	}
}

void	handle_flag_space(int flag_space, int len_word, size_t *len)
{
	int	nb_space;

	nb_space = flag_space - len_word;
	while (nb_space-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}
