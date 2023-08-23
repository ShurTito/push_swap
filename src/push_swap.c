/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:47:15 by antferna          #+#    #+#             */
/*   Updated: 2023/08/23 14:43:21 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	initialize_data(t_data *data)
{
	data->arr = NULL;
	data->i = 0;
	data->j = 0;
	data->lst_size = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

int	main2(t_data *data)
{
	if (init_stack_a(data) == EXIT_FAILURE)
		return (ft_free_full_arr(data->arr),
			ft_lstclear(&data->stack_a, &del_content),
			ft_putendl_fd("Error", 2),
			EXIT_FAILURE);
	data->lst_size = ft_lstsize(data->stack_a);
	put_index(data);
	if (check_order(data) == EXIT_FAILURE)
	{
		if (data->lst_size == 2)
			sa(data, 1);
		else if (data->lst_size == 3)
			sort_3(data);
		else
			sort_all(data);
	}
	ra_rra(data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	initialize_data(data);
	if (argc == 2)
	{
		if (check_args2(argv, data) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		if (check_args(argv, data, argc) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else
		return (free(data), EXIT_FAILURE);
	if (main2(data) == EXIT_FAILURE)
		return (free(data), EXIT_FAILURE);
	return (ft_free_full_arr(data->arr),
		ft_lstclear(&data->stack_a, &del_content),
		ft_lstclear(&data->stack_b, &del_content),
		free(data),
		EXIT_SUCCESS);
}
