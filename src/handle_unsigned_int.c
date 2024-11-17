/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:10:56 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 14:48:44 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_nbr_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_uitoa_recur_base(unsigned int n, int *i, char *nbr_str, char *base, int base_len)
{
	if (n >= (unsigned int)base_len)
	{
		ft_uitoa_recur_base(n / base_len, i, nbr_str, base, base_len);
		ft_uitoa_recur_base(n % base_len, i, nbr_str, base, base_len);
	}
	else
		nbr_str[(*i)++] = base[n];
}

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*to_return;
	int		len;
	int		i;
	int		base_len;
	
	base_len = ft_strlen(base);
	len = ft_nbr_len(n);
	to_return = (char *)malloc(len + 1);
	if (!to_return)
		return (NULL);
	i = 0;
	ft_uitoa_recur_base(n, &i, to_return, base, base_len);
	to_return[i] = '\0';
	return (to_return);
}

void	handle_unsigned_int(unsigned int value, t_flags *flags, size_t *len)
{
	char	*str_nbr;
	int		size;

	str_nbr = ft_uitoa_base(value, "0123456789");
	size = ft_strlen(str_nbr);
	if (!flags->left)
	{
		handle_flag_space(flags->space, size, len);
		handle_flag_zero(flags->zero, size, len);
	}
	ft_putstr_fd(str_nbr, 1);
	*len += size;
	if (flags->left)
		handle_flag_space(flags->space, size, len);
	free(str_nbr);
}

