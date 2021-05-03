/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:08:55 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/03 16:58:44 by kmacquet         ###   ########.fr       */
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
		printf("|%d(%d)  %d(%d)|", data->stack_a ? data->stack_a->i : 0,data->stack_a ? data->stack_a->group : 0,
		data->stack_b ? data->stack_b->i : 0, data->stack_b ? data->stack_b->group : 0);
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

t_data	*init(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->command = NULL;
	data->a_size = 0;
	data->b_size = 0;
	data->group_size = 0;
	data->current_group = 0;
	data->next_group = 0;
	data->pivot = 0;
	data->y_max = 0;
	return (data);
}

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

int		count_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int		count_group(t_stack *stack)
{
	int	i;
	int	group;

	i = 0;
	group = stack->group;
	while (stack && stack->group == group)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	new_pivot(t_data *data, char c, int size)
{
	int	i;
	int	tab[size];
	t_stack	*init;
	t_stack *stack;

	i = 0;
	if (c == 'a')
	{
		stack = data->stack_a;
		data->a_size = count_stack(stack);
	}
	else
	{
		stack = data->stack_b;
		data->b_size = count_stack(stack);
	}
	data->y_max = count_stack(stack);
	data->group_size = count_group(stack);
	print_stack(data);
	while (stack && size--)
	{
		tab[i] = stack->i;
		stack = stack->next;
		i++;
	}
	presort_tab(tab, data);
	i = 0;
	data->pivot = tab[(int)(data->group_size / 2)];
	printf("[%d]\n", data->pivot);
}
