/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:39:19 by antferna          #+#    #+#             */
/*   Updated: 2023/08/22 12:58:16 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_data *data)
{
	long long	min;
	t_list		*aux;
	t_list		*node_min;
	int			index;

	min = (long long)MAX_INT + 1;
	node_min = data->stack_a;
	index = 1;
	aux = data->stack_a;
	while (data->lst_size >= index)
	{
		while (aux)
		{
			if (aux->value < min && aux->index == 0)
			{
				min = aux->value;
				node_min = aux;
			}
			aux = aux->next;
		}
		min = (long long)MAX_INT + 1;
		node_min->index = index;
		aux = data->stack_a;
		index++;
	}
}

int	check_order(t_data *data)
{
	int		i;
	t_list	*aux;

	i = 1;
	aux = data->stack_a;
	while (data->lst_size >= i)
	{
		if (i != aux->index)
			return (EXIT_FAILURE);
		aux = aux->next;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	sort_3(t_data *data)
{
	t_list	*lst;

	lst = data->stack_a;
	if (lst->index > lst->next->index && lst->index > lst->next->next->index)
	{
		ra(data, 1);
		lst = data->stack_a;
		if (lst->index > lst->next->index)
			sa(data, 1);
	}
	else if (lst->next->index > lst->index
		&& lst->next->index > lst->next->next->index)
	{
		rra(data, 1);
		lst = data->stack_a;
		if (lst->index > lst->next->index)
			sa(data, 1);
	}
	else if (lst->index < lst->next->index
		&& lst->index < lst->next->next->index
		&& lst->next->index < lst->next->next->index)
		return ;
	else
		sa(data, 1);
}

void	sort_all(t_data *data)
{
	t_list	*cheap_node;

	while (ft_lstsize(data->stack_a) > 3)
		pb(data, 1);
	sort_3(data);
	while (data->stack_b)
	{
		set_pos(data);
		set_target_pos(data);
		set_cost_b(data);
		set_cost_a(data);
		cheap_node = cheapest_node(data);
		if (cheap_node->cost_a < 0 && cheap_node->cost_b < 0)
			sort_all_1(data, cheap_node);
		else if (cheap_node->cost_a > 0 && cheap_node->cost_b > 0)
			sort_all_2(data, cheap_node);
		else
			sort_all_3(data, cheap_node);
		pa(data, 1);
	}
}
