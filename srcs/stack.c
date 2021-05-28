/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:08:55 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 11:07:53 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

t_stack	*new_pivot2(t_data *data, char c, t_stack *stack)
{
	if (c == 'a')
	{
		stack = data->stack_a;
		data->a_size = count_group(stack);
	}
	else
	{
		stack = data->stack_b;
		data->b_size = count_group(stack);
	}
	return (stack);
}

void	new_pivot(t_data *data, char c, int size)
{
	int		*tab;
	t_stack	*init;
	t_stack	*stack;

	tab = malloc(size);
	if (!tab)
		ft_error("Malloc failed", data);
	data->y = 0;
	stack = new_pivot2(data, c, stack);
	data->y_max = count_group(stack);
	data->group_size = count_group(stack);
	while (stack && size--)
	{
		tab[data->y++] = stack->i;
		stack = stack->next;
	}
	presort_tab(tab, data);
	data->y = 0;
	data->pivot = tab[(int)(data->group_size / 2)];
	free(tab);
}

int	count_stack(t_stack *stack)
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

int	count_group(t_stack *stack)
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
