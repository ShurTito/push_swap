/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:08:34 by antferna          #+#    #+#             */
/*   Updated: 2023/08/22 12:49:21 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * reservamos memoria del tamaño de la estructura
 * ponemos el contenido del nodo con el content y el siguiente nodo
 * a NULL y devolvemos el puntero a la lista
 * 
 * @param content void * | puntero generico para almacenar cualquier dato
 * @return t_list* | puntero a la lista
 */
t_list	*ft_lstnew(int value, int index, int pos, int target_pos)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->value = value;
	new_lst->index = index;
	new_lst->pos = pos;
	new_lst->target_pos = target_pos;
	new_lst->cost_a = 0;
	new_lst->cost_b = 0;
	new_lst->next = NULL;
	return (new_lst);
}
