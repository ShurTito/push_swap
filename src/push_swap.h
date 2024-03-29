/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:50:06 by antferna          #+#    #+#             */
/*   Updated: 2023/08/22 13:00:18 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_data
{
	char		**arr;
	int			i;
	int			j;
	int			lst_size;
	t_list		*stack_a;
	t_list		*stack_b;
}				t_data;

int				check_args(char **argv, t_data *data, int argc);
int				check_args2(char **argv, t_data *data);
void			ft_free_full_arr(char **arr);
long long int	ft_atol(const char *str);
int				init_stack_a(t_data *data);
void			del_content(int content);
void			sa(t_data *data, int flag);
void			sb(t_data *data, int flag);
void			ss(t_data *data, int flag);
void			pb(t_data *data, int flag);
void			pa(t_data *data, int flag);
void			ra(t_data *data, int flag);
void			rb(t_data *data, int flag);
void			rr(t_data *data, int flag);
void			rra(t_data *data, int flag);
void			rrb(t_data *data, int flag);
void			rrr(t_data *data, int flag);
void			put_index(t_data *data);
int				check_order(t_data *data);
void			sort_all(t_data *data);
void			sort_all_1(t_data *data, t_list *cheap_node);
void			sort_all_2(t_data *data, t_list *cheap_node);
void			sort_all_3(t_data *data, t_list *cheap_node);
void			sort_3(t_data *data);
void			set_pos(t_data *data);
void			set_target_pos(t_data *data);
void			set_cost_b(t_data *data);
void			set_cost_a(t_data *data);
t_list			*cheapest_node(t_data *data);
int				cost(t_list *aux_b);
void			ra_rra(t_data *data);
int				max_index_stack_a(t_data *data);
void			ft_free_full_arr(char **arr);
int				is_sorted(t_list **stack);

#endif