/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:37:09 by antferna          #+#    #+#             */
/*   Updated: 2023/08/23 14:52:02 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_arr(char **arr, size_t index)
{
	size_t	i;

	if (arr != NULL)
	{
		i = 0;
		while (i < index)
		{
			if (arr[i] != NULL)
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	ft_free_full_arr(char **arr)
{
	size_t	i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

int	check_args(char **argv, t_data *data, int argc)
{
	data->i = 0;
	data->arr = ft_calloc(argc, sizeof(char *));
	if (!data->arr)
		return (ft_putendl_fd("Error", 2), EXIT_FAILURE);
	while (argv[++data->i] != NULL)
	{
		data->j = -1;
		if (argv[data->i][0] == '\0')
			return (ft_free_arr(data->arr, (data->i - 1))
				, ft_putendl_fd("Error", 2), EXIT_FAILURE);
		while (argv[data->i][++data->j] != '\0')
		{
			if (data->j == 0 && argv[data->i][data->j] == '-')
				data->j++;
			if (!ft_isdigit(argv[data->i][data->j]))
				return (ft_free_arr(data->arr, (data->i - 1)),
					ft_putendl_fd("Error", 2), EXIT_FAILURE);
		}
		data->arr[data->i - 1] = ft_calloc(ft_strlen(argv[data->i]) + 1, 1);
		if (!data->arr[data->i - 1])
			return (ft_free_arr(data->arr, (data->i - 1)), EXIT_FAILURE);
		ft_strlcpy(data->arr[data->i - 1], argv[data->i],
			ft_strlen(argv[data->i]) + 1);
	}
	return (data->arr[data->i - 1] = NULL, EXIT_SUCCESS);
}

int	check_args2(char **argv, t_data *data)
{
	int		i;
	int		j;

	if (argv[1] != NULL)
	{
		data->arr = ft_split(argv[1], ' ');
		if (!data->arr)
			return (EXIT_FAILURE);
		if (!data->arr[0])
			return (ft_free_full_arr(data->arr), ft_putendl_fd("Error", 2), 1);
		i = -1;
		while (data->arr[++i] != NULL)
		{
			j = -1;
			while (data->arr[i][++j] != '\0')
			{
				if (j == 0 && data->arr[i][j] == '-')
					j++;
				if (!ft_isdigit(data->arr[i][j]))
					return (ft_free_full_arr(data->arr),
						ft_putendl_fd("Error", 2), EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}
