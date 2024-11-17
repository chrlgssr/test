/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 06:23:15 by cgrasser          #+#    #+#             */
/*   Updated: 2024/11/09 06:31:58 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst)->next)
		ft_lstclear((&(*lst)->next), del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
