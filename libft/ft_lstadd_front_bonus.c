/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:22:26 by antferna          #+#    #+#             */
/*   Updated: 2023/08/22 12:49:12 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * si el nuevo nodo es NULL nos salimos, si lst es NULL igualamos lst
 * a new y nos salimos si no, new-next equivale al primero nodo de lst
 * y lst equivale a new
 * 
 * @param lst t_list ** | direccion de memoria de nuestra lista
 * @param new t_list * | nuevo nodo a añadir al principio de la lista
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
