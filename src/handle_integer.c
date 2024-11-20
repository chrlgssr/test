/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:01:48 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/20 21:36:07 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_join_and_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}

void	handle_flag_print(int is_negative, t_flags *flags, size_t *len)
{
	if (is_negative)
		ft_putchar_fd('-', 1);
	else if (flags->plus)
		ft_putchar_fd('+', 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
	(*len)++;
}

void	handle_integer_no_minus(int is_negative, t_flags *flags, size_t *len, int size_s)
{
	if ((is_negative || flags->plus || flags->space) && flags->zero)
	{
		handle_flag_print(is_negative, flags, len);
		handle_flag_width(flags->width, size_s + 1, len, ZERO);
	}
	else if ((is_negative || flags->plus || flags->space))
	{
		handle_flag_width(flags->width, size_s + 1, len, SPACE);
		handle_flag_print(is_negative, flags, len);
	}
	else if (flags->zero)
		handle_flag_width(flags->width, size_s, len, ZERO);
	else 
		handle_flag_width(flags->width, size_s, len, SPACE);
}

void	handle_integer_precision(int is_negative, char *str_nbr,
	t_flags *flags, size_t *len)
{
	char *padding;
	int	size_s;

	size_s = ft_strlen(str_nbr);
	padding = ft_calloc(flags->precision - size_s + 1, sizeof(char));
	ft_memset(padding, '0', flags->precision - size_s);
	str_nbr = ft_join_and_free(padding, str_nbr);
	if (is_negative)
		str_nbr = ft_join_and_free("-", str_nbr);
	else if (flags->plus)
		str_nbr = ft_join_and_free("+", str_nbr);
	else if (flags->space)
		str_nbr = ft_join_and_free(" ", str_nbr);
	size_s = ft_strlen(str_nbr);
	if (!flags->minus)
		handle_flag_width(flags->width, size_s, len, SPACE);
	ft_putstr_fd(str_nbr, 1);
	if (flags->minus)
		handle_flag_width(flags->width, size_s, len, SPACE);
	*len += ft_strlen(str_nbr);
	free(str_nbr);
}
char	*convert_positive(char *s)
{
	char	*tmp;

	tmp = ft_strdup(&s[1]);
	free(s);
	return (tmp);
}
void	handle_integer(int value, t_flags *flags, size_t *len)
{
	char	*str_nbr;
	char	*tmp;
	int		size_s;
	int 	is_negative;
	
	is_negative = (value < 0);
	str_nbr = ft_itoa(value);
	if (is_negative)
	{
		tmp = convert_positive(str_nbr);
		str_nbr = tmp;
	}
	size_s = ft_strlen(str_nbr);
	if (flags->precision > size_s)
		return (handle_integer_precision(is_negative, str_nbr, flags, len));
	if (!flags->minus)
		handle_integer_no_minus(is_negative, flags, len, size_s);
	else if(is_negative || flags->plus || flags->space)
		handle_flag_print(is_negative, flags, len);
	ft_putstr_fd(str_nbr, 1);
	if (flags->minus)
	{
		if (is_negative || flags->plus || flags->space)
			handle_flag_width(flags->width, size_s + 1, len, SPACE);
		else
			handle_flag_width(flags->width, size_s, len, SPACE);
	}
	free(str_nbr);
	*len += size_s;
}
