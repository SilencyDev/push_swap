/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:01 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/02 17:08:07 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	is_solved(t_data *data)
{
	if (!data->stack_a)
		ft_status(0);
	while (data->stack_a)
	{
		if ((data->stack_a->next
			&& data->stack_a->i > data->stack_a->next->i)
			|| data->stack_b)
			ft_status(0);
		data->stack_a = data->stack_a->next;
	}
	ft_status(1);
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
	t_data	*data;

	data = malloc(sizeof(t_data));
	data = init(data);
	parsing_nb(data, av);
	parsing_cmd(data);
	if (!data->stack_a)
		return (0);
	print_stack(data);
	check_cmd(data);
	is_solved(data);
}
