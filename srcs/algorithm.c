/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:40:07 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/28 18:40:11 by kmacquet         ###   ########.fr       */
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
	if (data->stack_a->i > data->stack_a->next->i && write(1, "sb\n", 3))
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
	int	group;

	group = 1;
	i = data->y_max;
	print_stack(data);
	while (data->stack_a && data->y_max > 2)
	{
		while (i-- > 2 && data->stack_a)
		{
			if (data->stack_a->i <= data->pivot)
			{
				pb(data);
				data->stack_b->group = group;
			}
			else
				ra(data);
			print_stack(data);
		}
		group++;
		new_pivot(data, 'a');
		i = data->y_max;
		printf("[%d]\n", data->pivot);
		print_stack(data);
	}
	xxs_algo(data);
	print_stack(data);
	new_pivot(data, 'b');
	i = data->y_max;
	while (data->stack_b && data->y_max > 2)
	{
		while (i-- > 2 && data->stack_b)
		{
			if (data->stack_b->i >= data->pivot)
			{
				pa(data);
				data->stack_a->group = group;
			}
			else
				rb(data);
			// print_stack(data);
		}
		group++;
		new_pivot(data, 'b');
		i = data->y_max;
		printf("[%d]\n", data->pivot);
		print_stack(data);
	}
	xxs_ralgob(data);
	pa(data);
	pa(data);
	print_stack(data);
	exit(0);
	// if (data->stack_a->i)
	// 	while (data->stack_a->next)
	// 	{
	// 		printf("i[%d] n[%p] p[%p]\n", data->stack_a->i ,data->stack_a->next, data->stack_a->previous);
	// 		data->stack_a = data->stack_a->next;
	// 	}
	// printf("i[%d] n[%p] p[%p]\n", data->stack_a->i ,data->stack_a->next, data->stack_a->previous);
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
