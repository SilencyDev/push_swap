/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:23:22 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/31 17:55:14 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	pa(t_data *data)
{
	t_stack	*first_a;

	first_a->next = data->stack_a;
	first_a->previous = NULL;
	first_a->i = data->stack_b->i;
	data->stack_a = first_a;
	data->stack_b = data->stack_b->next;
	data->stack_b->previous = NULL;
}

void	pb(t_data *data)
{
	t_stack	*first_b;

	first_b->next = data->stack_b;
	first_b->previous = NULL;
	first_b->i = data->stack_a->i;
	data->stack_b = first_b;
	data->stack_a = data->stack_a->next;
	data->stack_a->previous = NULL;
}
