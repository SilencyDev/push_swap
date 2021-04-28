/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:21 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/28 11:25:26 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int		is_solved_tab(int *av, t_data *data)
{
	int	i;

	i = -1;
	while (data->y_max > ++i)
	{
		if ((data->y_max - 1 != i) && av[i] > av[i + 1])
			return (0);
		if ((data->y_max - 1 != i) && av[i] == av[i + 1])
			ft_error("Numbers can't be identical", data);
	}
	return (1);
}

void	presort_tab(int *av, t_data *data)
{
	int	tmp;
	int	i;

	i = 0;
	while (data->y_max > i && !is_solved_tab(av, data))
	{
		if (data->y_max - 1 != i && av[i] > av[i + 1])
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
		}
		i++;
	}
	if (!is_solved_tab(av, data))
		presort_tab(av, data);
}

void	set_pivot(t_data *data)
{
	int	i;
	int	tab[data->y_max];
	t_stack	*init;

	i = 0;
	init = data->stack_a;
	while (data->y_max > i && data->stack_a)
	{
		tab[i] = data->stack_a->i;
		data->stack_a = data->stack_a->next;
		i++;
	}
	data->stack_a = init;
	presort_tab(tab, data);
	data->pivot = tab[(int)(data->y_max / 2)];
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
		if (!data.stack_a)
			return (0);
		set_pivot(&data);
		// print_stack(&data);
		while (!is_solved2(&data, 1))
			solving(&data, ac);
		ft_status(3, &data);
	}
	return (0);
}
