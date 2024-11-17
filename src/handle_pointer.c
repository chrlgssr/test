/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:05:57 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 12:54:57 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_ptrlen(unsigned long int ptr)
{
	size_t	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr >= 1)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	ft_ptrtoa_base_recur(unsigned long int nb, int *i, char *base, char *to_return, int base_len)
{
	if (nb >= (unsigned long int)base_len)
	{
		ft_ptrtoa_base_recur(nb / base_len, i, base, to_return, base_len);
		ft_ptrtoa_base_recur(nb % base_len, i, base, to_return, base_len);
	}
	else
		to_return[(*i)++] = base[nb];

}

static char *ft_ptrtoa_base(unsigned long int nb, char *base)
{
	char	*to_return;
	int		len;
	int		i;
	int		base_len;
	
	base_len = ft_strlen(base);
	len = ft_ptrlen(nb) + 2;
	to_return = (char *)malloc((len + 1) * sizeof(char));
	if (!to_return)
		return (NULL);
	i = 0;
	to_return[i++] = '0';
	to_return[i++] = 'x';
	ft_ptrtoa_base_recur(nb, &i, base, to_return, base_len);
	to_return[i] = '\0';
	return (to_return);
}

static void	ft_nil(size_t *len)
{
	ft_putstr_fd("(nil)", 1);
	*len += 5;
}

void	handle_pointer(unsigned long int ptr, t_flags *flags, size_t *len)
{
	char	*str_ptr;
	int		size;
	if (!ptr)
		return (ft_nil(len));
	str_ptr = ft_ptrtoa_base(ptr, "0123456789abcdef");
	size = ft_strlen(str_ptr);
	if (!flags->left)
		handle_flag_space(flags->space, size, len);
	ft_putstr_fd(str_ptr, 1);
	*len += size;
	if (flags->left)
		handle_flag_space(flags->space, size, len);
	free(str_ptr);
}
