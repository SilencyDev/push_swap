/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:21 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/27 17:23:02 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int		is_solved_tab(int *av, t_data *data)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (av[i + 1] && av[i] > av[i + 1])
			return (0);
		if (av[i + 1] && av[i] == av[i + 1])
			ft_error("Numbers can't be identical", data);
	}
	return (1);
}

void	presort_tab(int *av, t_data *data)
{
	int	tmp;
	int	i;

	i = 0;
	while (!is_solved_tab(av, data))
	{
		if (av[i + 1] && av[i] > av[i + 1])
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

void	set_pivot(char **av, t_data *data)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * data->y_max);
	while (data->y_max > i && av[i])
	{
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	presort_tab(tab, data);
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
		// print_stack(&data);
		while (!is_solved(&data, 1))
			solving(&data, ac);
		ft_status(3, &data);
	}
	return (0);
}
