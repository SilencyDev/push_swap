/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:40:07 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 07:58:21 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	xs_algo(t_data *data)
{
	if (data->stack_a->next->next->i < data->stack_a->i
		&& data->stack_a->next->next->i < data->stack_a->next->i
		&& data->stack_a->i > data->stack_a->next->i)
	{
		write(1, "sa\nrra\n", 7);
		sa(data);
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
	else if (data->stack_a->i > data->stack_a->next->next->i)
	{
		write(1, "ra\n", 3);
		ra(data);
	}
	else if (data->stack_a->i > data->stack_a->next->i)
	{
		write(1, "sa\n", 3);
		sa(data);
	}
}

void	xxs_algo(t_data *data)
{
	if (data->stack_a->i > data->stack_a->next->i)
	{
		write(1, "sa\n", 3);
		sa(data);
	}
}

void	xxs_ralgob(t_data *data)
{
	if (data->stack_b->i < data->stack_b->next->i)
	{
		write(1, "sb\n", 3);
		sb(data);
	}
}

void	s_algo(t_data *data)
{
	int			i;
	static int	group = 1;
	int			nb_left;
	int			ret;

	while (!is_solved2(data))
	{
		while (!pre_solved(data))
		{
			ret = 0;
			nb_left = count_group(data->stack_a);
			new_pivot(data, 'a', nb_left);
			if (nb_left == 2)
				xxs_algo(data);
			else if (nb_left == 3 && data->stack_a->group == 0)
				xs_algo(data);
			else
			{
				while (nb_left)
				{
					if (data->stack_a->i < data->pivot)
					{
						write(1, "pb\n", 3);
						pb(data);
						data->stack_b->group = group;
					}
					else if (nb_left > 0)
					{
						write(1, "ra\n", 3);
						ra(data);
						ret++;
					}
					nb_left--;
				}
				group++;
				if (count_stack(data->stack_a) == 3 && data->stack_a->group == 0)
					xs_algo(data);
				else
				{
					while (ret-- && data->stack_a && data->stack_a->next)
					{
						write(1, "rra\n", 4);
						rra(data);
					}
				}
			}
		}
		ret = 0;
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
		{
			while (nb_left)
			{
				if (data->stack_b->i >= data->pivot || !data->stack_b->next)
				{
					write(1, "pa\n", 3);
					pa(data);
					data->stack_a->group = group;
				}
				else
				{
					write(1, "rb\n", 3);
					rb(data);
					ret++;
				}
				nb_left--;
			}
			group++;
			while (ret-- && data->stack_b && data->stack_b->next)
			{
				write(1, "rrb\n", 4);
				rrb(data);
			}
		}
	}
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
