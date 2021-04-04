/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:55:30 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/04 22:20:53 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void		rra(t_data *data)
{
	t_stack	*s_init;

	if (!data->stack_a && !data->stack_a->next)
		ft_error("Can't rrotate stack A if there is less than 2 elements", data);
	s_init = data->stack_a;
	while (data->stack_a->next)
		data->stack_a = data->stack_a->next;
	data->stack_a->next = s_init;
	(data->stack_a->previous)->next = NULL;
	data->stack_a->previous = NULL;
	s_init->previous = data->stack_a;
}

void		rrb(t_data *data)
{
	t_stack	*s_init;

	if (!data->stack_b && !data->stack_b->next)
		ft_error("Can't rrotate stack B if there is less than 2 elements", data);
	s_init = data->stack_b;
	while (data->stack_b->next)
		data->stack_b = data->stack_b->next;
	data->stack_b->next = s_init;
	(data->stack_b->previous)->next = NULL;
	data->stack_b->previous = NULL;
	s_init->previous = data->stack_b;
}

void	rrr(t_data *d)
{
	rra(d);
	rrb(d);
}
