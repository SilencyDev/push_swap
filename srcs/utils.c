/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:08:55 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/28 11:25:43 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_stack(t_data *data)
{
	t_stack *a;
	t_stack *b;

	a = data->stack_a;
	b = data->stack_b;
	printf("------\n");
	while (data->stack_a || data->stack_b)
	{
		printf("|%d  %d|", data->stack_a ? data->stack_a->i : 0, data->stack_b ? data->stack_b->i : 0);
		printf("\n");
		if (data->stack_a && data->stack_a->next)
			data->stack_a = data->stack_a->next;
		else
			data->stack_a = NULL;
		if (data->stack_b && data->stack_b->next)
			data->stack_b = data->stack_b->next;
		else
			data->stack_b = NULL;
	}
	printf("------\n");
	data->stack_a = a;
	data->stack_b = b;
}

void	is_solved(t_data *data, int push_swap)
{
	t_stack	*init;

	init = data->stack_a;
	if (!data->stack_a)
		ft_status(0, data);
	while (data->stack_a)
	{
		if ((data->stack_a->next
			&& data->stack_a->i > data->stack_a->next->i)
			|| data->stack_b)
		{
			data->stack_a = init;
			ft_status(0, data);
		}
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = init;
	ft_status(1, data);
}

int	is_solved2(t_data *data, int push_swap)
{
	t_stack	*init;

	init = data->stack_a;
	if (!data->stack_a)
		return (0);
	while (data->stack_a)
	{
		if ((data->stack_a->next
			&& data->stack_a->i > data->stack_a->next->i)
			|| data->stack_b)
		{
			data->stack_a = init;
			return (0);
		}
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = init;
	return (1);
}

t_data	*init(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->command = NULL;
	data->pivot = 0;
	data->y_max = 0;
	return (data);
}
