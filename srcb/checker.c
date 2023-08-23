/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:25:03 by antferna          #+#    #+#             */
/*   Updated: 2023/08/23 13:33:21 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ft_free_stacks(t_data *data)
{
	if (data->stack_a)
		ft_lstclear(&data->stack_a, &del_content);
	if (data->stack_b)
		ft_lstclear(&data->stack_b, &del_content);
}

void	initialize_data(t_data *data)
{
	data->arr = NULL;
	data->i = 0;
	data->j = 0;
	data->lst_size = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

int	check_line(char **line, t_data *data)
{
	if (ft_strncmp(*line, "pb\n", 3) == 0)
		return (pb(data, 0), 0);
	else if (ft_strncmp(*line, "pa\n", 3) == 0)
		return (pa(data, 0), 0);
	else if (ft_strncmp(*line, "sa\n", 3) == 0)
		return (sa(data, 0), 0);
	else if (ft_strncmp(*line, "sb\n", 3) == 0)
		return (sb(data, 0), 0);
	else if (ft_strncmp(*line, "ss\n", 3) == 0)
		return (ss(data, 0), 0);
	else if (ft_strncmp(*line, "ra\n", 3) == 0)
		return (ra(data, 0), 0);
	else if (ft_strncmp(*line, "rb\n", 3) == 0)
		return (rb(data, 0), 0);
	else if (ft_strncmp(*line, "rr\n", 3) == 0)
		return (rr(data, 0), 0);
	else if (ft_strncmp(*line, "rra\n", 3) == 0)
		return (rra(data, 0), 0);
	else if (ft_strncmp(*line, "rrb\n", 3) == 0)
		return (rrb(data, 0), 0);
	else if (ft_strncmp(*line, "rrr\n", 3) == 0)
		return (rrr(data, 0), 0);
	return (EXIT_FAILURE);
}

int	main2(t_data *data)
{
	char	*line;

	if (init_stack_a(data) == EXIT_FAILURE)
		return (ft_free_full_arr(data->arr),
			ft_free_stacks(data), ft_putendl_fd("Error", 2), EXIT_FAILURE);
	if (is_sorted(&data->stack_a) && data->stack_b == NULL)
		return (ft_printf("OK\n"), EXIT_SUCCESS);
	line = get_next_line(0);
	while (line)
	{
		if (check_line(&line, data) == EXIT_FAILURE)
			return (free(line), ft_free_full_arr(data->arr),
				ft_free_stacks(data), ft_putendl_fd("Error", 2), EXIT_FAILURE);
		else
		{
			free(line);
			if (is_sorted(&data->stack_a) && data->stack_b == NULL)
				return (ft_printf("OK\n"), EXIT_SUCCESS);
			line = get_next_line(0);
		}
	}
	return (ft_printf("KO\n"), EXIT_SUCCESS);
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
		ft_free_stacks(data), free(data), EXIT_SUCCESS);
}
