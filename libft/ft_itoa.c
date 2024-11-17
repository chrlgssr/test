/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42perpigan.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:54:52 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/08 16:23:46 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_recur(int n, size_t *i, char *nbr_str)
{
	if (n >= 10)
	{
		ft_itoa_recur(n / 10, i, nbr_str);
		ft_itoa_recur(n % 10, i, nbr_str);
	}
	else
		nbr_str[(*i)++] = n + 48;
}

char	*ft_itoa(int n)
{
	char	*to_return;
	size_t	len;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = nbr_len(n);
	to_return = (char *)malloc(len + 1);
	if (!to_return)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		to_return[i++] = '-';
		n = -n;
	}
	ft_itoa_recur(n, &i, to_return);
	to_return[i] = '\0';
	return (to_return);
}
