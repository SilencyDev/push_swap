/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:40:07 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 11:59:40 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	s_algo_a(t_data *data, int nb_left)
{
	while (nb_left)
	{
		if (data->stack_a->i < data->pivot)
		{
			write(1, "pb\n", 3);
			pb(data);
			data->stack_b->group = data->group;
		}
		else if (nb_left > 0 && write(1, "ra\n", 3))
		{
			ra(data);
			data->ret++;
		}
		nb_left--;
	}
	data->group++;
	if (count_stack(data->stack_a) == 3 && data->stack_a->group == 0)
		xs_algo(data);
	else
		while (data->ret-- && data->stack_a && data->stack_a->next
			&& write(1, "rra\n", 4))
			rra(data);
}

void	s_algo_b(t_data *data, int nb_left)
{
	while (nb_left)
	{
		if (data->stack_b->i >= data->pivot || !data->stack_b->next)
		{
			write(1, "pa\n", 3);
			pa(data);
			data->stack_a->group = data->group;
		}
		else if (write(1, "rb\n", 3))
		{
			rb(data);
			data->ret++;
		}
		nb_left--;
	}
	data->group++;
	while (data->ret-- && data->stack_b && data->stack_b->next
		&& write(1, "rrb\n", 4))
		rrb(data);
}

void	s_algo_presolved(t_data *data)
{
	int	nb_left;

	while (!pre_solved(data))
	{
		data->ret = 0;
		nb_left = count_group(data->stack_a);
		new_pivot(data, 'a', nb_left);
		if (nb_left == 2)
			xxs_algo(data);
		else if (nb_left == 3 && data->stack_a->group == 0)
			xs_algo(data);
		else
			s_algo_a(data, nb_left);
	}
}

void	s_algo(t_data *data)
{
	int			nb_left;

	data->group = 1;
	while (!is_solved2(data))
	{
		s_algo_presolved(data);
		data->ret = 0;
		nb_left = count_group(data->stack_b);
		new_pivot(data, 'b', nb_left);
		if (nb_left == 2)
		{
			xxs_ralgob(data);
			write(1, "pa\npa\n", 6);
			pa(data);
			pa(data);
		}
		else
			s_algo_b(data, nb_left);
	}
}
