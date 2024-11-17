/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:01:30 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 14:16:10 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_flags(const char *s, t_flags *flags, size_t *i)
{
	if (s[*i] == '-')
	{
		flags->left = 1;
		(*i)++;
	}
	else if (s[*i] == '0')
		while (ft_isdigit(s[++(*i)]))
			flags->zero = flags->zero * 10 + (s[*i] - '0');
	else if (s[*i] == '.')
		while (ft_isdigit(s[++(*i)]))
			flags->precision *= 10 + (s[*i] - '0');
	else if (ft_isdigit(s[*i]))
		while (ft_isdigit(s[*i]))
			flags->space = flags->space * 10 + (s[(*i)++] - '0');
}

void	handle_format(va_list args, char specifier, size_t *total_len, t_flags *flags)
{
	if (specifier == 'c')
		handle_char(va_arg(args, int), flags, total_len);
	if (specifier == 's')
		handle_string(va_arg(args, char *), flags, total_len);
	if (specifier == 'p')
		handle_pointer((unsigned long int)va_arg(args, void *), flags, total_len);
	if (specifier == 'd' || specifier == 'i')
		handle_integer(va_arg(args, int), flags, total_len);
	if (specifier == 'u')
		handle_unsigned_int(va_arg(args, unsigned int), flags, total_len);
	if (specifier == 'x' || specifier == 'X')
		handle_hexadecimal(va_arg(args, unsigned long), flags, total_len, specifier);
	if (specifier == '%')
		handle_char('%', flags, total_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags	*flags;
	size_t	i;
	size_t	total_len;

	i = 0;
	total_len = 0;
	flags = ft_flagsnew();
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1])
			{
				i++;
				while (!ft_strchr("cspdiuxX%", s[i]) && (ft_strchr("-0.", s[i]) || ft_isdigit(s[i])))
					handle_flags(s, flags, &i);
				handle_format(args, s[i], &total_len, flags);
				ft_reset_flags(flags);
			}
		}
		else
			handle_char(s[i], flags, &total_len);
		i++;
	}
	free(flags);
	va_end(args);
	return (total_len);
}


