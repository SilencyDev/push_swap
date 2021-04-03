/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:01 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/03 18:21:03 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	is_solved(t_data *data)
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

t_data	*init(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->command = NULL;
	return (data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 2)
	{
		data = *init(&data);
		if (ac == 2)
			parsing_nb(&data, av);
		else
			parsing_nb2(&data, av, ac);
		parsing_cmd(&data);
		if (!data.stack_a)
			return (0);
		print_stack(&data);
		if (data.command)
			check_cmd(&data);
		is_solved(&data);
	}
	return (0);
}
