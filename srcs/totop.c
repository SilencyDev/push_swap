/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:55:30 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/31 17:54:10 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void		rra(t_data *data)
{
	t_stack	*s_init;

	s_init = data->stack_a;
	while (data->stack_a->next)
		data->stack_a = data->stack_a->next;
	data->stack_a->next = s_init;
	s_init->previous = data->stack_a;
	(data->stack_a->previous)->next = NULL;
	data->stack_a->previous = NULL;
	data->stack_a = s_init;
}

void		rrb(t_data *data)
{
	t_stack	*s_init;

	s_init = data->stack_b;
	while (data->stack_b->next)
		data->stack_b = data->stack_b->next;
	data->stack_b->next = s_init;
	s_init->previous = data->stack_b;
	(data->stack_b->previous)->next = NULL;
	data->stack_b->previous = NULL;
	data->stack_b = s_init;
}

void	rrr(t_data *d)
{
	rra(d);
	rrb(d);
}
