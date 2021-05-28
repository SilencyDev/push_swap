/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobottom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:45:26 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 07:29:33 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ra(t_data *data)
{
	t_stack	*s_init;
	t_stack	*new_first;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	s_init = data->stack_a;
	(data->stack_a->next)->previous = NULL;
	new_first = data->stack_a->next;
	while (data->stack_a->next)
		data->stack_a = data->stack_a->next;
	data->stack_a->next = s_init;
	s_init->previous = data->stack_a;
	s_init->next = NULL;
	data->stack_a = new_first;
}

void	rb(t_data *data)
{
	t_stack	*s_init;
	t_stack	*new_first;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	s_init = data->stack_b;
	(data->stack_b->next)->previous = NULL;
	new_first = data->stack_b->next;
	while (data->stack_b->next)
		data->stack_b = data->stack_b->next;
	data->stack_b->next = s_init;
	s_init->previous = data->stack_b;
	s_init->next = NULL;
	data->stack_b = new_first;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
