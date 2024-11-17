/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 08:14:20 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/17 14:43:04 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

//=====================================================================| FLAGS |

typedef struct s_flags
{
	int	left;
	int	zero;
	int	precision;
	int	space;
}	t_flags;

t_flags	*ft_flagsnew(void);
void	ft_reset_flags(t_flags *flags);

//==============================================================| HANDLE FLAGS |

void	handle_flag_space(int flag_space, int len_word, size_t *len);
void	handle_flag_zero(int flag_zero, int len_word, size_t *len);

//====================================================================| PRINTF |

int		ft_printf(const char *s, ...);

//=============================================================| HANDLE FORMAT |

void	handle_char(int value, t_flags *flags, size_t *len);
void	handle_string(char *s, t_flags *flags, size_t *len);
void	handle_pointer(unsigned long int ptr, t_flags *flags, size_t *len);
void	handle_integer(int value, t_flags *flags, size_t *len);
void	handle_unsigned_int(unsigned int value, t_flags *flags, size_t *len);
void	handle_hexadecimal(unsigned int hex, t_flags *flags, size_t *len, char f);

//=====================================================================| UTILS |

char	*ft_uitoa_base(unsigned int n, char *base);

#endif
