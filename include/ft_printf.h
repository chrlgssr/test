/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 08:14:20 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/20 20:18:23 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>
# define SPACE 1
# define ZERO 0

//=====================================================================| FLAGS |

typedef struct {
    int plus;      // Flag '+'
    int minus;     // Flag '-'
    int hash;      // Flag '#'
    int zero;      // Flag '0'
    int space;     // Flag ' ' (espace)
    int precision;  // Flag '.'
    int width;      // Largeur minimale
} t_flags;

t_flags	*ft_flagsnew(void);
void	ft_reset_flags(t_flags *flags);

//==============================================================| HANDLE FLAGS |

void	handle_flag_width(int width, int len_word, size_t *len, int c);
void	handle_integer_precision(int is_negative, char *str_nbr, t_flags *flags, size_t *len);
void	handle_integer_no_minus(int is_negative, t_flags *flags, size_t *len, int size_s);
void	handle_flag_print(int is_negative, t_flags *flags, size_t *len);
char	*ft_join_and_free(char *s1, char *s2);

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
char	*ft_ptrtoa_base(unsigned long int nb, char *base);

#endif
