/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:23:22 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 07:30:34 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	pa(t_data *data)
{
	t_stack	*stack;

	if (!data->stack_b)
		return ;
	stack = data->stack_b;
	if (data->stack_b->next)
	{
		data->stack_b = data->stack_b->next;
		data->stack_b->previous = NULL;
	}
	else
		data->stack_b = NULL;
	ft_lstadd_front(data, stack);
}

void	pb(t_data *data)
{
	t_stack	*stack;

	if (!data->stack_a)
		return ;
	stack = data->stack_a;
	if (data->stack_a->next)
	{
		data->stack_a = data->stack_a->next;
		data->stack_a->previous = NULL;
	}
	else
		data->stack_a = NULL;
	ft_lstadd_frontb(data, stack);
}
