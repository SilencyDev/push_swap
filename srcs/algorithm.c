/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:40:07 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/03 23:59:54 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	xs_algo(t_data *data)
{
	if (data->stack_a->i > data->stack_a->next->next->i && write(1, "ra\n", 3))
		ra(data);
	else if (data->stack_a->i > data->stack_a->next->i && write(1, "sa\n", 3))
		sa(data);
	else if (data->stack_a->next->i > data->stack_a->i
		&& data->stack_a->next->i > data->stack_a->next->next->i)
	{
		sa(data);
		ra(data);
		write(1, "sa\nra\n", 6);
	}
	// print_stack(data);
}

void	xxs_algo(t_data *data)
{
	if (data->stack_a->i > data->stack_a->next->i && write(1, "sa\n", 3))
		sa(data);
	// print_stack(data);
}

int		smallest(int i, t_stack *stack)
{
	t_stack	*init;

	init = stack;
	while (stack && i < stack->i && stack->next)
	{
		if (!stack->next)
			return (1);
		stack = stack->next;
	}
	stack = init;
	return (0);
}

int		get_median(t_data *data)
{
	return (0);
}

void	s_algo(t_data *data)
{
	int	median;

	median = get_median(data);

	// pb(data);
	// write(1, "pb\n", 3);
	// xs_algo(data);
	// pa(data);
	// write(1, "pa\n", 3);
	// if (data->stack_a->i > data->stack_a->next->i && write(1, "ra\n", 3))
	// {
	// 	ra(data);
	// }
	// pa(data);
	// write(1, "pa\n", 3);
		// print_stack(data);
}

void	solving(t_data *data, int ac)
{
	if (data->y_max == 2)
		xxs_algo(data);
	else if (data->y_max == 3)
		xs_algo(data);
	else if (data->y_max == 5)
		s_algo(data);
}
