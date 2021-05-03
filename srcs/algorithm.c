/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:40:07 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/03 16:59:07 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	xs_algo(t_data *data)
{
	if (data->stack_a->next->next->i < data->stack_a->i
		&& data->stack_a->next->next->i < data->stack_a->next->i
		&& data->stack_a->i > data->stack_a->next->i)
	{
		write(1, "sa\n", 3);
		sa(data);
		write(1, "rra\n", 4);
		rra(data);
	}
	else if (data->stack_a->next->next->i < data->stack_a->i
		&& data->stack_a->next->next->i < data->stack_a->next->i)
	{
		write(1, "rra\n", 4);
		rra(data);
	}
	else if (data->stack_a->next->i > data->stack_a->i
		&& data->stack_a->next->i > data->stack_a->next->next->i)
	{
		write(1, "sa\nra\n", 6);
		sa(data);
		ra(data);
	}
	else if (data->stack_a->i > data->stack_a->next->next->i && write(1, "ra\n", 3))
		ra(data);
	else if (data->stack_a->i > data->stack_a->next->i && write(1, "sa\n", 3))
		sa(data);
	// print_stack(data);
}

void	xs_ralgob(t_data *data)
{
	if (data->stack_b->next->next->i > data->stack_b->i
		&& data->stack_b->next->next->i > data->stack_b->next->i
		&& data->stack_b->i < data->stack_b->next->i)
	{
		write(1, "sb\n", 3);
		sb(data);
		write(1, "rrb\n", 4);
		rrb(data);
	}
	else if (data->stack_b->next->next->i > data->stack_b->i
		&& data->stack_b->next->next->i > data->stack_b->next->i)
	{
		write(1, "rrb\n", 4);
		rrb(data);
	}
	else if (data->stack_b->next->i < data->stack_b->i
		&& data->stack_b->next->i < data->stack_b->next->next->i)
	{
		write(1, "sb\nrb\n", 6);
		sb(data);
		rb(data);
	}
	else if (data->stack_b->i < data->stack_b->next->next->i && write(1, "rb\n", 3))
		rb(data);
	else if (data->stack_b->i < data->stack_b->next->i && write(1, "sb\n", 3))
		sb(data);
	// print_stack(data);
}

void	xxs_algo(t_data *data)
{
	if (data->stack_a->i > data->stack_a->next->i && write(1, "sa\n", 3))
		sa(data);
	// print_stack(data);
}

void	xxs_ralgo(t_data *data)
{
	if (data->stack_a->i < data->stack_a->next->i && write(1, "sa\n", 3))
		sa(data);
	// print_stack(data);
}

void	xxs_ralgob(t_data *data)
{
	if (data->stack_b->i < data->stack_b->next->i && write(1, "sb\n", 3))
		sb(data);
	// print_stack(data);
}

// int		smallest(int i, t_stack *stack)
// {
// 	t_stack	*init;

// 	init = stack;
// 	while (stack && i < stack->i && stack->next)
// 	{
// 		if (!stack->next)
// 			return (1);
// 		stack = stack->next;
// 	}
// 	stack = init;
// 	return (0);
// }

// int		get_median(t_data *data)
// {
// 	int	tab[INT_MAX];
// 	return (0);
// }


void	s_algo(t_data *data)
{
	int	i;
	static int	group = 1;

	new_pivot(data, 'a', count_stack(data->stack_a));
	print_stack(data);
	while (data->stack_a && data->a_size > 2)
	{
		while (data->stack_a && data->a_size > 2)
		{
			if (count_group(data->stack_a) == 3)
				xs_algo(data);
			if (data->stack_a->i <= data->pivot)
			{
				pb(data);
				data->stack_b->group = group;
				print_stack(data);
			}
			else
			{
				ra(data);
				print_stack(data);
			}
			data->a_size--;
		}
		data->current_group = group++;
		data->next_group = group;
		new_pivot(data, 'a', count_group(data->stack_a));
	}
	// while (!is_solved2(data))
	// {
	// 	if (pre_solved(data))
	// 	{
	// 		new_pivot(data, 'b', count_stack(data->stack_b));
	// 		while (data->stack_b && count_group(data->stack_b) > 1)
	// 		{
	// 			if (count_group(data->stack_b) == 2)
	// 				xxs_ralgob(data);
	// 			if (data->stack_b->i >= data->pivot)
	// 			{
	// 				pa(data);
	// 				data->stack_b->group = group;
	// 			}
	// 			else
	// 			{
	// 				rb(data);
	// 			}

	// 		}
	// 	}
	// 	else
	// 	{

	// 	}
	// }
	exit(0);
}

void	solving(t_data *data, int ac)
{
	if (data->y_max == 2)
		xxs_algo(data);
	else if (data->y_max == 3)
		xs_algo(data);
	else if (data->y_max > 3)
		s_algo(data);
}
