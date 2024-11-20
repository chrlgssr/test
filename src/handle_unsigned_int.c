/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:10:56 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/20 19:46:11 by cgrasser         ###   ########.fr       */
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
	int		size_s;
	
	str_nbr = ft_uitoa_base(value, "0123456789");
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

