/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:08:55 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 10:28:21 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

// void	print_stack(t_data *data)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = data->stack_a;
// 	b = data->stack_b;
// 	printf("------\n");
// 	while (data->stack_a || data->stack_b)
// 	{
// 		printf("|%d(%d)  %d(%d)|", data->stack_a ?
//		data->stack_a->i : 0,data->stack_a ? data->stack_a->group : 0,
// 		data->stack_b ? data->stack_b->i : 0, data->stack_b ?
//		data->stack_b->group : 0);
// 		printf("\n");
// 		if (data->stack_a && data->stack_a->next)
// 			data->stack_a = data->stack_a->next;
// 		else
// 			data->stack_a = NULL;
// 		if (data->stack_b && data->stack_b->next)
// 			data->stack_b = data->stack_b->next;
// 		else
// 			data->stack_b = NULL;
// 	}
// 	printf("------\n");
// 	data->stack_a = a;
// 	data->stack_b = b;
// }

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

int	pre_solved(t_data *data)
{
	t_stack	*init;

	init = data->stack_a;
	if (!data->stack_a)
		return (0);
	while (data->stack_a)
	{
		if ((data->stack_a->next
				&& data->stack_a->i > data->stack_a->next->i))
		{
			data->stack_a = init;
			return (0);
		}
		data->stack_a = data->stack_a->next;
	}
	data->stack_a = init;
	return (1);
}

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

int	is_solved2(t_data *data)
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

int	is_solved_tab(int *av, t_data *data)
{
	int	i;

	i = -1;
	while (data->y_max > ++i)
	{
		if (av[i] > INT_MAX || av[i + 1] > INT_MAX)
			ft_error("Numbers can't be higher than INT MAX", data);
		if ((data->y_max - 1 != i) && av[i] > av[i + 1])
			return (0);
		if ((data->y_max - 1 != i) && av[i] == av[i + 1])
			ft_error("Numbers can't be identical", data);
	}
	return (1);
}
