/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:39:44 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 10:56:57 by cgrasser         ###   ########.fr       */
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
	flags->left = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->space = 0;
}
